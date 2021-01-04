#include "Flooding.h"

Define_Module(Flooding);

Flooding::Flooding()
  : msg(nullptr)
  , timer(nullptr)
  , status(Status::IDLE)
{ }

Flooding::~Flooding()
{
  cancelAndDelete(timer);
}

void Flooding::initialize()
{
  int initiator = par("initiator").intValue();
  WATCH(status);
  WATCH(data);
  if (initiator == getIndex()) {
    status = Status::INITIATOR;
    EV_INFO << "Node " << getIndex() << " is the initiator\n";
  }
  if (status == Status::INITIATOR) { //A1
    data = par("data").intValue();
    omnetpp::simtime_t startTime = par("startTime");
    msg = new FloodingMessage("flooding", MsgKind::FLOODING);
    msg->setData(data);
    timer = new omnetpp::cMessage("timer", MsgKind::TIMER);
    scheduleAt(startTime, timer);
  }
}

void Flooding::handleMessage(omnetpp::cMessage* recv_msg)
{
  if (status == Status::INITIATOR)
  {
    if (recv_msg->getKind() == MsgKind::TIMER) {
      int n = gateSize("port$o");
      for (int i = 0; i < n - 1; i++)
        send(msg->dup(), "port$o", i);
      send(msg, "port$o", n - 1);
      status = Status::DONE;
      EV_INFO << "Node " << getIndex() << " is " << status << "\n";
    }
  }
  else if (status == Status::IDLE)   // A2
  {
    if(recv_msg->getKind() == MsgKind::FLOODING)
    {
      auto floodingMessage = dynamic_cast<FloodingMessage*>(recv_msg);
      data = floodingMessage->getData();
      int gateIndex = floodingMessage->getArrivalGate()->getIndex();
      int n = gateSize("port$o");
      for (int i = 0; i < n; i++)
        if (i != gateIndex)
          send(floodingMessage->dup(), "port$o", i);
      status = Status::DONE;
      EV_INFO << "Node " << getIndex() << " is " << status << "\n";
      bubble("I'm DONE");
      delete recv_msg;
    }
  }
}

void Flooding::refreshDisplay() const
{
  omnetpp::cDisplayString& display_str = getDisplayString();
  if (status == DONE)
    display_str.setTagArg("i", 1, "green");
  else
    display_str.setTagArg("i", 1, "");
}


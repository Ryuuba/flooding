#ifndef FLOODING_H
#define FLOODING_H

#include <omnetpp.h>
#include "Flooding_m.h"

class Flooding : public omnetpp::cSimpleModule {
public:
  enum Status {
    INITIATOR = 1,
    IDLE = 2,
    DONE = 3
  };
  enum MsgKind {
    FLOODING = 10,
    TIMER = 11,
    OTHER = 12
  };
protected:
  /** @brief The data this node floods */
  int data;
  /** @brief The message carrying the data */
  FloodingMessage* msg;
  /** @brief The time at which the first message is sent */
  omnetpp::cMessage* timer;
  /** @brief The status of this node */
  Status status;
  //** @brief Changes the icon of the app to indicate the host status */
  virtual void refreshDisplay() const override;

public:
  /** @brief Creates the attributes of this class assigning default values */
  Flooding();
  /** @brief Frees memory */
  virtual ~Flooding();
  /** @brief Parses the data's value as well as the ID of the initiator, then
   *  performs actions corresponding to the event Spontaneously
  */
  virtual void initialize();
  /** @brief Performs the actions of the Flooding protocol corresponding to
   *  the reception of a message.
   */
  virtual void handleMessage(omnetpp::cMessage*);
};

#endif // FLOODING_H

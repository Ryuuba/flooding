//
// Generated file, do not edit! Created by nedtool 5.6 from Flooding.msg.
//

#ifndef __FLOODING_M_H
#define __FLOODING_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>Flooding.msg:1</tt> by nedtool.
 * <pre>
 * message FloodingMessage
 * {
 *     int data;
 * }
 * </pre>
 */
class FloodingMessage : public ::omnetpp::cMessage
{
  protected:
    int data;

  private:
    void copy(const FloodingMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const FloodingMessage&);

  public:
    FloodingMessage(const char *name=nullptr, short kind=0);
    FloodingMessage(const FloodingMessage& other);
    virtual ~FloodingMessage();
    FloodingMessage& operator=(const FloodingMessage& other);
    virtual FloodingMessage *dup() const override {return new FloodingMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getData() const;
    virtual void setData(int data);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const FloodingMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, FloodingMessage& obj) {obj.parsimUnpack(b);}


#endif // ifndef __FLOODING_M_H


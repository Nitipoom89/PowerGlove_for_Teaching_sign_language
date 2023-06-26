//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#include <CANFDMessage.h>

//--------------------------------------------------------------------------------------------------

class ACANFD_FeatherM4CAN_FIFO {

  //································································································
  // Default constructor
  //································································································

  public: ACANFD_FeatherM4CAN_FIFO (void) ;

  //································································································
  // Destructor
  //································································································

  public: ~ ACANFD_FeatherM4CAN_FIFO (void) ;

  //································································································
  // Private properties
  //································································································

  private: CANFDMessage * mBuffer ;
  private: uint16_t mSize ;
  private: uint16_t mReadIndex ;
  private: uint16_t mCount ;
  private: uint16_t mPeakCount ; // > mSize if overflow did occur

  //································································································
  // Accessors
  //································································································

  public: inline uint16_t size (void) const { return mSize ; }
  public: inline uint16_t count (void) const { return mCount ; }
  public: inline bool isEmpty (void) const { return mCount == 0 ; }
  public: inline bool isFull (void) const { return mCount == mSize ; }
  public: inline uint16_t peakCount (void) const { return mPeakCount ; }

  //································································································
  // initWithSize
  //································································································

  public: void initWithSize (const uint16_t inSize) ;

  //································································································
  // append
  //································································································

  public: bool append (const CANFDMessage & inMessage) ;

  //································································································
  // Remove
  //································································································

  public: bool remove (CANFDMessage & outMessage) ;

  //································································································
  // Free
  //································································································

  public: void free (void) ;

  //································································································
  // Reset Peak Count
  //································································································

  public: inline void resetPeakCount (void) { mPeakCount = mCount ; }

  //································································································
  // No copy
  //································································································

  private: ACANFD_FeatherM4CAN_FIFO (const ACANFD_FeatherM4CAN_FIFO &) ;
  private: ACANFD_FeatherM4CAN_FIFO & operator = (const ACANFD_FeatherM4CAN_FIFO &) ;
} ;

//--------------------------------------------------------------------------------------------------
/*
 *  $Id: tdmessage.h,v 1.3 2003/08/19 19:20:00 tuexen Exp $
 *
 * SocketAPI implementation for the sctplib.
 * Copyright (C) 1999-2003 by Thomas Dreibholz
 *
 * Realized in co-operation between
 * - Siemens AG
 * - University of Essen, Institute of Computer Networking Technology
 * - University of Applied Sciences, Muenster
 *
 * Acknowledgement
 * This work was partially funded by the Bundesministerium fuer Bildung und
 * Forschung (BMBF) of the Federal Republic of Germany (Foerderkennzeichen 01AK045).
 * The authors alone are responsible for the contents.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * There are two mailinglists available at http://www.sctp.de which should be
 * used for any discussion related to this implementation.
 *
 * Contact: discussion@sctp.de
 *          dreibh@exp-math.uni-essen.de
 *          tuexen@fh-muenster.de
 *
 * Purpose: Socket Message
 *
 */



#ifndef TDMESSAGE_H
#define TDMESSAGE_H


#include "tdsystem.h"
#include "socketaddress.h"


#include <sys/uio.h>
#include <sys/types.h>
#include <sys/socket.h>



/**
  * This template class manages manages message structures used by
  * sendmsg() and recvmsg(). The template parameter gives the size
  * of the control data block.
  *
  * @short   Socket Message
  * @author  Thomas Dreibholz (dreibh@exp-math.uni-essen.de)
  * @version 1.0
  */
template<const size_t size> class SocketMessage
{
   // ====== Constructor ====================================================
   public:
   /**
     * Constructor.
     */
   inline SocketMessage();


   // ====== Structure manipulation =========================================
   /**
     * Clear structure.
     */
   inline void clear();

   /**
     * Get address as SocketAddress object. Note: This address has to be freed
     * using delete operator!
     *
     * @return SocketAddress object.
     */
   inline SocketAddress* getAddress() const;

   /**
     * Set address.
     *
     * @param address SocketAddress object.
     */
   inline void setAddress(const SocketAddress& address);

   /**
     * Set buffer.
     *
     * @param buffer Buffer.
     * @param bufferSize Size of buffer.
     */
   inline void setBuffer(char* buffer, const size_t buffersize);

   /**
     * Set size of control block. Sizes greater than the template parameter
     * are adjusted to the maximum possible value.
     *
     * @param controlsize Size of controlblock.
     */
   inline void setControl(const size_t controlsize);

   /**
     * Add control header of given cmsg level and type. Returns NULL,
     * if there is not enough free space in the control data block.
     *
     * @param payload Size of payload.
     * @param level Level (e.g. IPPROTO_SCTP).
     * @param type Type (e.g. SCTP_INIT).
     * @return Pointer to begin of *payload* area.
     */
   inline char* addHeader(const cardinal payload,
                          const int      level,
                          const int      type);

   /**
     * Get first cmsg header in control block.
     *
     * @return First cmsg header or NULL, if there are none.
     */
   inline cmsghdr* getFirstHeader() const;

   /**
     * Get next cmsg header in control block.
     *
     * @param prev Previous cmsg header.
     * @return Next cmsg header or NULL, if there are no more.
     */
   inline cmsghdr* getNextHeader(const cmsghdr* prev) const;


   // ====== Message structures =============================================
   /**
     * msghdr structure.
     */
   msghdr Header;

   /**
     * Storage for address.
     */
   sockaddr_storage Address;

   /**
     * iovec structure.
     */
   struct iovec IOVector;

   private:
   cmsghdr* NextMsg;

   /**
     * Control data block, its size is given by the template parameter.
     */
   public:
   char Control[size];
};


/**
  * Wrapper for CMSG_SPACE macro.
  */
#if (SYSTEM == OS_SOLARIS)
#define CSpace(payload) (_CMSG_DATA_ALIGN(sizeof(struct cmsghdr)) + _CMSG_DATA_ALIGN(payload))
#else
#define CSpace(payload) CMSG_SPACE(payload)
#endif

/**
  * Wrapper for CMSG_LEN macro.
  */

#if (SYSTEM == OS_SOLARIS)
#define CLength(l) (_CMSG_DATA_ALIGN(sizeof(struct cmsghdr)) + (l))
#else
#define CLength(l) CMSG_LEN(l)
#endif

/**
  * Wrapper for CMSG_DATA macro.
  */
inline static char* CData(const cmsghdr* cmsg);

/**
  * Wrapper for CMSG_FIRSTHDR macro.
  */
inline static cmsghdr* CFirst(const msghdr* header);

/**
  * Wrapper for CMSG_NXTHDR macro.
  */
inline static cmsghdr* CNext(const msghdr* header, const cmsghdr* cmsg);


#include "tdmessage.icc"


#endif

/*
 *  $Id: range.cc,v 1.2 2003/08/19 19:24:25 tuexen Exp $
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
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * There are two mailinglists available at http://www.sctp.de which should be
 * used for any discussion related to this implementation.
 *
 * Contact: discussion@sctp.de
 *          dreibh@exp-math.uni-essen.de
 *          tuexen@fh-muenster.de
 *
 * Purpose: Range Template
 *
 */


#include "tdsystem.h"
#include "range.h"


// ###### Default constructor ###############################################
template<class T> Range<T>::Range()
{
}


// ###### Constructor #######################################################
template<class T> Range<T>::Range(T min, T max, T value)
{
   init(min,max,value);
}


// ###### Initialization ####################################################
template<class T> void Range<T>::init(T min, T max, T value)
{
   if(min < max) {
      Min   = min;
      Max   = max;
   }
   else {
      Max = min;
      Min = max;
   }
   Value = value;
   if(Value != 0) {
      if(Value < Min) Value = Min;
      if(Value > Max) Value = Max;
   }
}


// ###### Output operator ###################################################
template<class T> ostream& operator<<(ostream& os, const Range<T>& range)
{
   cout << range.Min << " <= " << range.Value << " <= " << range.Max;
   return(os);
}

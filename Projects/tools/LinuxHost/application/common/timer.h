/**************************************************************************************************
  Filename:       timer.h
  Revised:        $Date: 2012-01-27 14:33:06 -0800 (fr, 27 jan 2012) $
  Revision:       $Revision: 184 $

  Description:    This file contains a sample OAD Server application


  Copyright (C) {YEAR} Texas Instruments Incorporated - http://www.ti.com/


   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

     Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the
     distribution.

     Neither the name of Texas Instruments Incorporated nor the names of
     its contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**************************************************************************************************/


#ifndef TIMER_H_
#define TIMER_H_

#include "common_app.h"

#if !defined PACK_1
#define PACK_1
#endif

#if defined(_MSC_VER) || defined(unix) || (defined(__ICC430__) && (__ICC430__==1))
#pragma pack(1)
#endif

typedef struct
{
	uint32 		eventFlag;
	long int 	timeoutValue[32];	// 1 timer per event
	uint32 		timerEnabled;		// Maps to event mask
	uint32		justKicked;
} timer_thread_s ;

#if defined _MSC_VER || defined(unix)
#pragma pack()
#endif

extern int    timer_init			(uint16 numOfThreads);

extern uint8  timer_start_timerEx	(uint8 threadId, uint32 event, uint32 timeout);
extern uint8  timer_isActive		(uint8 threadId, uint32 event);
extern uint8  timer_set_event		(uint8 threadId, uint32 event);
extern uint8  timer_clear_event		(uint8 threadId, uint32 event);
extern uint32 timer_get_event		(uint8 threadId);

#endif /* TIMER_H_ */

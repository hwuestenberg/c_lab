/******************************************************************************
 * This program implements a stopwatch for use in C.
 *
 * Copyright (C) 2008 Dominik Juergens (d.juergens@tu-bs.de)
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, see <http://www.gnu.org/licenses/>.
 * ******************************************************************************/

#ifndef _STOPWATCH_H_
#define _STOPWATCH_H_

#include <sys/time.h>
#include <sys/times.h>
#include <stdio.h>

/********************************************/
/* Makros for simple use of the stopwatch;  */
/* A simple user-interface:                 */
/* Usage: start_timer();pause_timer();...   */
/*        printf("Timer: %fs",read_timer());*/
/********************************************/
#define start_timer()        stopwatch_start(&global_timer)
#define pause_timer()        stopwatch_pause(&global_timer)
#define read_timer()         getRealTime    (&global_timer)
#define read_system_timer()  getSystemTime  (&global_timer)
#define read_user_timer()    getUserTime    (&global_timer)
/********************************************/
/* END OF USER INTERFACE                    */
/********************************************/

#define FALSE 0
#define TRUE  1

/* simple struct to represent a timer-stamp */
typedef struct time_struct
{
  double real,system,user;
} Time;

/* struct Stopwatch contains the state-information of a stopwatch */
typedef struct stopwatch_struct
{
  struct timeval     value;        // struct timeval defined in <time.h>
  struct timezone    zone;         // struct timezone defined in <time.h>
  struct tms  process_time;        // struct tms defined in <sys/times.h>
  double r_time1, s_time1, u_time1;// memory for a time state
  double r_time2, s_time2, u_time2;// memory for a second time state
  int    paused;                   // boolean state variable
} Stopwatch;

/*Global instance for use of Makros start_timer(),pause_timer(),read_timer()*/
  static Stopwatch global_timer;

/* init the given stopwatch */
  void stopwatch_init(Stopwatch*);

/* starts/resets the given stopwatch */
  void stopwatch_start(Stopwatch*);

/* pauses the given stopwatch */
  void stopwatch_pause(Stopwatch*);

/* Reads User Time on Stopwatch*/
  double getUserTime(Stopwatch*);

/* Reads System Time on Stopwatch*/
  double getSystemTime(Stopwatch*);

/* Reads Real Time on Stopwatch*/
  double getRealTime(Stopwatch*);

/* Reads Time (Real,System,User) on Stopwatch*/
  Time getTime(Stopwatch*);

#endif

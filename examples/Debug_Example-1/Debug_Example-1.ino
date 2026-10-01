//******************************************************************
//
//     A r n o T e k  D e b u g   E x a m p l e   1  
//
//        Use conditional compilation print statements.
//
//------------------------------------------------------------------
//
//  Copyright 2026 Anthony J. Arnovitz  All rights reserved.
//
//******************************************************************

// Include the heartbeat class to toggle the Arduino LED 
#include <ArnoTek_HeartBeat.h>


// *** Configure Debugging ***
//     Note that the definition of the ArnoTek_Debug variable must come before the include statement

//#define ArnoTek_DEBUG 0
#define ArnoTek_DEBUG 1
#include "ArnoTek_Debug.h"


// Define callback for timer function
void TimerFunctionCallback(long unsigned);


//                  C o n s t r u c t o r s
ArnoTek_HeartBeat HeartBeat(500);       // Define heartbeat object to toggle the on board Arduino LED every half second

ArnoTek_HeartBeat TimerFunction(5000, &TimerFunctionCallback);  



//                  * * *   S E T U P   * * *

void setup() 
{
  delay(4000);

  // *** Conditionally configure and send these message to the serial monitor ***

  // ArnoTek_DebugInit(115200);
  // ArnoTek_DebugLn("\n\n*** Starting setup ***\n");

  // ArnoTek_DebugLn("*** Setup complete ***\n");

  //----------------------------------------------------------------------

  // *** Always send these messages to the serial monitor ***

  Serial.begin(115200);
  Serial.println("\n\n*** Starting setup ***\n");

  Serial.println("*** Setup complete ***\n");
}



//                  * * *   L O O P   * * *

void loop() 
{
  HeartBeat.Toggle();     // (not necessary for ArnoTek_Debug utility)

  TimerFunction.Toggle();
}



//                  * * *   C a l l b a c k   F u n c t i o n s   * * *

void TimerFunctionCallback(long unsigned myCurrentTime)
{
  // Conditionally send messages to the serial monitor
  ArnoTek_Debug("TimerFunctionCallback entered: ");
  ArnoTek_Debug(myCurrentTime);
  ArnoTek_Debug("\t (0x");
  ArnoTek_Debug2(myCurrentTime, HEX);
  ArnoTek_DebugLn(")");
}
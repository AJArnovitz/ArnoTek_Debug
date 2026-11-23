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



//          * * *   C o n f i g u r e   D e b u g g i n g   * * *

//     The debugging configuration MUST be specified BEFORE including the ArnoTek_Debug.h file.

#define ArnoTek_DEBUG 0

#define ArnoTek_DEBUG_Terse 1

#define ArnoTek_DEBUG_Verbose 1


// Now that debugging has been defined, include the ArnoTek_Debug.h file
#include <ArnoTek_Debug.h>



// Include the heartbeat class to toggle the Arduino LED 
#include <ArnoTek_HeartBeat.h>



//                  * * *   C o n s t r u c t o r s   * * *

ArnoTek_HeartBeat HeartBeat((long unsigned)250);                                     // Define heartbeat object (quarter second timer)

// Note: You can reference the ArnoTek debugging controls in your code if you wish
#if ArnoTek_DEBUG == 1
    ArnoTek_HeartBeat TimerFunction;   
#endif

ArnoTek_HeartBeat SpacerFunction; 
    



//                  * * *   D e f i n e   g l o b a l   V a r i a b l e s   * * *

long unsigned myTimer;





//                  * * *   S E T U P   * * *

void setup() 
{
  delay(4000);

  Serial.begin(115200);
  Serial.println("\n\n*** Starting setup ***");

  // Conditional print debug statments
  ArnoTek_DebugLn("\n\t*** Standard debugging is on ***");
  ArnoTek_DebugLn_Terse("\t\t*** Terse debugging is on  ***");
  ArnoTek_DebugLn_Verbose("\t\t*** Verbose debugging is on  ***");

  ArnoTek_DebugLn_Terse("\n\t'Terse' debugging is on, waiting an additional 4 seconds");
  ArnoTek_DebugDelay_Terse(4000);   // Wait another 4 seconds if "Terse" debugging is on

  myTimer = millis();

  // Note: You can reference the ArnoTek debugging controls in your code if you wish
  #if ArnoTek_DEBUG == 1
      TimerFunction.Init(myTimer, (long unsigned)2000, 0, &TimerFunctionCallback);     // Call the TimerFunctionCallback every 5 seconds
  #else
    Serial.println("\n\n\t*** Debugging is off ***\n");
  #endif

  SpacerFunction.Init(myTimer, (long unsigned)10001, 0, &SpacerFunctionCallback);  // Call the SpacerFunctionCallback every 25 seconds

  Serial.println("\n*** Setup complete ***\n\n");
}



//                  * * *   L O O P   * * *

void loop() 
{
  HeartBeat.Toggle();
  myTimer = millis();

  // Only generate the code if we are not debugging
  #if ArnoTek_DEBUG == 1
      TimerFunction.Toggle(myTimer);
  #endif

  SpacerFunction.Toggle(myTimer);
}



//                  * * *   C a l l b a c k   F u n c t i o n s   * * *

// We don't need to compile these functions if we are not debugging
#if ArnoTek_DEBUG == 1

    void TimerFunctionCallback(ArnoTek_HeartBeat *myObject, long unsigned myCurrentTime)
    {
      ArnoTek_Debug("TimerFunctionCallback entered: ");
      ArnoTek_Debug(myCurrentTime);
      ArnoTek_Debug("\t (0x");
      ArnoTek_Debug2(myCurrentTime, HEX);
      ArnoTek_Debug(")");
      ArnoTek_Debug_Terse("\t*** Terse ***");
      ArnoTek_Debug_Verbose("\t*** Verbose ***");
      ArnoTek_DebugLn("");
    }

#endif

  void SpacerFunctionCallback(ArnoTek_HeartBeat *myObject, long unsigned myCurrentTime)
  {   
    Serial.println("");
  }
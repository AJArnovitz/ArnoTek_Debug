//*******************************************************************************************
//	                             A r n o T e k _ D e b u g . h                              *
//                                                                                          *
//                   Copyright Anthony J. Arnovitz 2026    All rights reserved.             *
//                                                                                          *
//------------------------------------------------------------------------------------------*
//                                                                                          *
//     This include file defines the debugging definitions that duplicate the Serial        *
// methods.  If the ArnoTek_DEBUG compiler variable is set to 1, the duplicate methods are  *
// defined.  If it is not set to 1, the duplicate methods are defined as null and do not    *
// have an impact on the compiled code and do not generate any object/machine code.         *
//                                                                                          *
//     For Serial.print statements that have two parameters, use the ArnoTek_Debug2()       *
//  the ArnoTek_Debug2(,) or the ArnoTek_DebugLn2 statments.                                *
//                                                                                          *
//                                                                                          *
//                            * * *   N O T E   * * *                                       *
//                                                                                          *
//     There are two additional series of optional debugging statements available.  One     *
// has a suffix of "_Terse" and the other a suffice of "_Verbose".  These are active when   *
// the "ArnoTek_DEBUG_Terse" or the "ArnoTek_DEBUG_Verbose" compiler variables are set to 1 *
// respectively.  They function exactly like the ArnoTek_DEBUG compiler variables and they  *
// provide potentially three levels of debugging statements.  However, if the               *
// ArnoTek_DEBUG compiler variable is not set to one, *** ALL *** of the debugging          *
// statements are not generated.                                                            *
//                                                                                          *
//------------------------------------------------------------------------------------------*
//                                                                                          *
// How to use this code:                                                                    *
//     1. Copy this code to your Arduino library                                            *
//     2. Add "#include <ArnoTek_Debug.h>" to your source code                              *
//     3. Define ArnoTek_DEBUG = 1 to enable the serial print statements at compile time    *
//                         - - -  OR   - - -                                                *
//        Define ArnoTek_DEBUG = 0 to disable the serial print statements at compile time   *
//                                                                                          *
//        Note: The ArnoTek_Debug definition must come BEFORE the ArnoTek_Debug.h           *
//              include statement.                                                          *
//                                                                                          *
//     4. Use the various ArnoTek_Debug statements                                          *
//                                                                                          *
//                                                                                          *
// NOTE: If non-debugging serial input/output is used, do not use the ArnoTek_DebugInit     *
//       statement but instead use a Serial.begin statement prior to the ArnoTek_Debug      *
//       statements.                                                                        *
//                                                                                          *
//       The ArnoTek_DEBUG compile variable must be defined PRIOR to the                    *
//       #include <ArnoTek_Debug.h> statement in your code                                  *
//                                                                                          *
//------------------------------------------------------------------------------------------*
//                                                                                          *
// Example:                                                                                 *
//    #define ArnoTek_DEBUG 1                                                               *
//    - - -  OR   - - -                                                                     *
//    #define ArnoTek_DEBUG 0                                                               *
//        .                                                                                 *
//    #include <ArnoTek_Debug.h>                                                            *
//        .                                                                                 *
//        .                                                                                 *
//   ArnoTek_DebugInit(115200);  // Do not use if non-debugging serial interface is used    *
//                               // use Serial.begin instead                                *
//                                                                                          *
//   ArnoTek_DebugLn("");                                                                   *
//   ArnoTek_DebugLn("**********************************");                                 *
//   ArnoTek_DebugLn("*** Here is a heading ***");                                          *
//   ArnoTek_DebugLn("**********************************");                                 *
//   ArnoTek_DebugLn("");                                                                   *
//   ArnoTek_DebugLn2(someVariable, HEX);    // Display value in hexidecimal                *
//        .                                                                                 *
//        .                                                                                 *
//        .                                                                                 *
//                                                                                          *
//*******************************************************************************************

#ifndef ArnoTekDebug_H
    #define ArnoTekDebug_H

    #if ArnoTek_DEBUG == 1
        #define ArnoTek_DebugInit(x) Serial.begin(x)
        #define ArnoTek_Debug(x) Serial.print(x)
        #define ArnoTek_Debug2(x, y) Serial.print(x, y)
        #define ArnoTek_DebugLn(x) Serial.println(x)
        #define ArnoTek_DebugLn2(x, y) Serial.println(x, y)
        #define ArnoTek_DebugFlush() Serial.flush();
        #define ArnoTek_DebugDelay(x) delay(x)

        #if ArnoTek_DEBUG_Terse == 1
            #define ArnoTek_DebugInit_Terse(x) Serial.begin(x)
            #define ArnoTek_Debug_Terse(x) Serial.print(x)
            #define ArnoTek_Debug2_Terse(x, y) Serial.print(x, y)
            #define ArnoTek_DebugLn_Terse(x) Serial.println(x)
            #define ArnoTek_DebugLn2_Terse(x, y) Serial.println(x, y)
            #define ArnoTek_DebugFlush_Terse() Serial.flush();
            #define ArnoTek_DebugDelay_Terse(x) delay(x)
        #endif

        #if ArnoTek_DEBUG_Verbose == 1
            #define ArnoTek_DebugInit_Verbose(x) Serial.begin(x)
            #define ArnoTek_Debug_Verbose(x) Serial.print(x)
            #define ArnoTek_Debug2_Verbose(x, y) Serial.print(x, y)
            #define ArnoTek_DebugLn_Verbose(x) Serial.println(x)
            #define ArnoTek_DebugLn2_Verbose(x, y) Serial.println(x, y)
            #define ArnoTek_DebugFlush_Verbose() Serial.flush();
            #define ArnoTek_DebugDelay_Verbose(x) delay(x)
        #endif
    #else
        #define ArnoTek_DebugInit(x)
        #define ArnoTek_Debug(x) 
        #define ArnoTek_Debug2(x, y)
        #define ArnoTek_DebugLn(x) 
        #define ArnoTek_DebugLn2(x, y)
        #define ArnoTek_DebugFlush() 
        #define ArnoTek_DebugDelay(x)
    #endif

    #if ArnoTek_DEBUG != 1 ||  ArnoTek_DEBUG_Terse != 1
        #define ArnoTek_DebugInit_Terse(x)
        #define ArnoTek_Debug_Terse(x) 
        #define ArnoTek_Debug2_Terse(x, y)
        #define ArnoTek_DebugLn_Terse(x) 
        #define ArnoTek_DebugLn2_Terse(x, y)
        #define ArnoTek_DebugFlush_Terse() 
        #define ArnoTek_DebugDelay_Terse(x)
    #endif

    
    #if ArnoTek_DEBUG != 1 ||  ArnoTek_DEBUG_Verbose != 1
        #define ArnoTek_DebugInit_Verbose(x)
        #define ArnoTek_Debug_Verbose(x) 
        #define ArnoTek_Debug2_Verbose(x, y)
        #define ArnoTek_DebugLn_Verbose(x) 
        #define ArnoTek_DebugLn2_Verbose(x, y)
        #define ArnoTek_DebugFlush_Verbose() 
        #define ArnoTek_DebugDelay_Verbose(x)
    #endif
#endif
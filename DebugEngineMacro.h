/** \file DebugEngineMacro.h
\brief Define the macro for the debug 
\author alpha_one_x86
\version 0.3
\date 2010
\licence GPL3, see the file COPYING */

#ifndef DEBUGENGINEMACRO_H
#define DEBUGENGINEMACRO_H

/// \brief Macro for the debug log
#ifdef ULTRACOPIER_DEBUG
	#include "DebugEngine.h"
	#if defined (__FILE__) && defined (__LINE__)
		#define ULTRACOPIER_DEBUGCONSOLE(a,b) DebugEngine::addDebugInformationStatic(a,__func__,b,__FILE__,__LINE__)
	#else
		#define ULTRACOPIER_DEBUGCONSOLE(a,b) DebugEngine::addDebugInformationStatic(a,__func__,b)
	#endif
#else // ULTRACOPIER_DEBUG
	#define ULTRACOPIER_DEBUGCONSOLE(a,b) void()
#endif // ULTRACOPIER_DEBUG

#endif // DEBUGENGINEMACRO_H


 

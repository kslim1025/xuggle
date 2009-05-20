/*
 * Copyright (c) 2008, 2009 by Xuggle Incorporated.  All rights reserved.
 * 
 * This file is part of Xuggler.
 * 
 * You can redistribute Xuggler and/or modify it under the terms of the GNU
 * Affero General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any
 * later version.
 * 
 * Xuggler is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public
 * License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with Xuggler.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <com/xuggle/ferry/Logger.h>
#include <com/xuggle/ferry/LoggerStack.h>
#include "LoggerTest.h"

using namespace VS_CPP_NAMESPACE;

VS_LOG_SETUP(VS_CPP_PACKAGE);

void
LoggerTestSuite :: testOutputToStandardError()
{
  // Temporarily turn down logging to make a quiet output
  LoggerStack stack;
  stack.setGlobalLevel(Logger::LEVEL_ERROR, false);
  
  VS_LOG_ERROR("This is an error message");
  VS_LOG_WARN("This is a warning message");
  VS_LOG_INFO("This is an info message");
  VS_LOG_DEBUG("This is a debug message");
  VS_LOG_TRACE("This is a trace message");

  VS_TUT_ENSURE("this test really just shouldn't crash.  check log files to ensure it outputted", true);
}


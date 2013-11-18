/* Copyright (C) 2013 Mokon, All Rights Reserved */

#pragma once

#include "config.h"
#include <glog/logging.h>
#include <iostream>

#define CONSOLE( ) std::cout

#define DEBUG_LOG_IF( ... ) __extension__ VLOG_IF( __VA_ARGS__ )

#define DEBUG_LOG_TRACE_V 1
#define DEBUG_LOG_TRACE_VV 2
#define DEBUG_LOG_TRACE_VVV 3
#define DEBUG_LOG_TRACE_VVVV 4
#define DEBUG_LOG_TRACE_VVVVV 5


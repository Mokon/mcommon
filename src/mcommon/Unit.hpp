/* Copyright (C) 2013 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

#include <utility>
#include <string>

namespace mcommon {

  enum Unit {
    MPH, MPM, MPS,
    HOURS, MINUTES, SECONDS,
    MILES
  } ;

  extern const std::string unitStrings[] ;

  #define UNIT_STRINGS { \
    "MPH", "MPM", "MPS", \
    "Hours", "Minutes", "Seconds", \
    "Miles" \
    } 

}


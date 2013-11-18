/* Copyright (C) 2013 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

#include <utility>
#include <string>

namespace mcommon {

  enum Unit {
    MPH, MPM, MPS, KPH,
    YEARS, HOURS, MINUTES, SECONDS,
    MILES, INCHES, KM,
    LBS, KG,
    METS,
    CALORIES
  } ;

  extern const std::string unitStrings[] ;

  #define UNIT_STRINGS { \
    "MPH", "MPM", "MPS", "KPH", \
    "Years", "Hours", "Minutes", "Seconds", \
    "Miles", "INCHES", "KM", \
    "LBS", "KG", \
    "METS", \
    "CALORIES" \
    } 

}


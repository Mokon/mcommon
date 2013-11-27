/* Copyright (C) 2013 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

#include <utility>
#include <string>

namespace mcommon {

  enum Unit {
    UNKNOWN_UNIT, NONE, PERCENTAGE,
    MPH, MPM, MPS, KPH,
    YEARS, HOURS, MINUTES, SECONDS,
    MILES, INCHES, MM, CM, KM,
    LBS, KG,
    METS,
    CALORIES
  } ;

  extern const std::string unitStrings[] ;

  #define UNIT_STRINGS { \
    "Unknown Unit", "", "%", \
    "mph", "mpm", "mps", "kph", \
    "Years", "Hours", "Minutes", "Seconds", \
    "Miles", "in", "mm", "cm", "km", \
    "lbs", "kg", \
    "METS", \
    "calories" \
    } 

}


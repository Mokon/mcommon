/* Copyright (C) 2013-2014 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "mcommon/Exception.hpp"

namespace mcommon {

  DEFINE_EXCEPTION_CLASS( UnknownUnitException ) ;

  enum Unit {
    UNKNOWN_UNIT, NONE, PERCENTAGE,
    MPH, MPM, MPS, KPH,
    YEARS, HOURS, MINUTES, SECONDS,
    MILES, INCHES, MM, CM, KM, M,
    LBS, KG,
    METS,
    CALORIES
  } ;

  extern const std::string unitStrings[] ;

  extern const std::map<std::string, Unit> unitMap ;

#define UNIT_MAP { \
  {"mph", MPH}, \
  {"mpm", MPM}, \
  {"mps", MPS}, \
  {"kph", KPH}, \
  {"Years", YEARS}, \
  {"years", YEARS}, \
  {"yrs", YEARS}, \
  {"Hours", HOURS}, \
  {"hours", HOURS}, \
  {"hrs", HOURS}, \
  {"Minutes", MINUTES}, \
  {"minutes", MINUTES}, \
  {"mins", MINUTES}, \
  {"min", MINUTES}, \
  {"Seconds", SECONDS}, \
  {"seconds", SECONDS}, \
  {"secs", SECONDS}, \
  {"sec", SECONDS}, \
  {"Miles", MILES}, \
  {"miles", MILES}, \
  {"mls", MILES}, \
  {"inches", INCHES}, \
  {"in", INCHES}, \
  {"mm", MM}, \
  {"MM", MM}, \
  {"cm", CM}, \
  {"CM", CM}, \
  {"M", M}, \
  {"m", M}, \
  {"meters", M}, \
  {"km", KM}, \
  {"KM", KM}, \
  {"lbs", LBS}, \
  {"LBS", LBS}, \
  {"kg", KG}, \
  {"KG", KG}, \
  {"mets", METS}, \
  {"METS", METS}, \
  {"cal", CALORIES}, \
  {"cals", CALORIES}, \
  {"calories", CALORIES}, \
  {"cals", CALORIES}, \
  {"none", NONE}}

  std::ostream& operator<<( std::ostream& os, const Unit& u ) ;

  std::istream& operator>>( std::istream& is, Unit& u ) ;

#define UNIT_STRINGS { \
  "Unknown Unit", "", "%", \
  "mph", "mpm", "mps", "kph", \
  "Years", "Hours", "Minutes", "Seconds", \
  "Miles", "in", "mm", "cm", "km", "m", \
  "lbs", "kg", \
  "METS", \
  "calories" \
}

  }


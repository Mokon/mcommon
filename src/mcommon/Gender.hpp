/* Copyright (C) 2013 Mokon, All Rights Reserved */

#pragma once

#include <iostream>
#include <string>
#include <string.h>

#include "mcommon/Exception.hpp"

namespace mcommon {
  
  DEFINE_EXCEPTION_CLASS( UnknownGenderException ) ;

  enum Gender {
    Male,
    Female,
    GENDER_MAX
  } ;

  std::ostream& operator<<( std::ostream& os, const Gender& g ) ;

  std::istream& operator>>( std::istream& is, Gender& g ) ;

  Gender toGender( std::string str ) ;

}


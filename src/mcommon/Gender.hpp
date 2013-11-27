/* Copyright (C) 2013 Mokon, All Rights Reserved */

#pragma once

#include <string>
#include <string.h>

namespace mcommon {

  enum Gender {
    Male,
    Female,
    GENDER_MAX
  } ;

  static inline Gender toGender( std::string str ) {
    if( str.compare( "Male" ) == 0 ) {
      return Male ;
    } else {
      return Female ;
    }
  } 

}


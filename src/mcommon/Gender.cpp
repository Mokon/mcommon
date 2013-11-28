/* Copyright (C) 2013 Mokon, All Rights Reserved */

#include "mcommon/Gender.hpp"

namespace mcommon {

  std::ostream& operator<<( std::ostream& os, const Gender& g ) {
    switch(  g ) {
      case Male:
        return os << "Male" ;
      default:
        return os << "Female" ;
    }
  }

  std::istream& operator>>( std::istream& is, Gender& g ) {
    char buf[255] ;
    is.getline(buf,255) ;

    g = toGender( buf ) ;

    return is ;
  }

  Gender toGender( std::string str ) {
    if( str.compare( "Male" ) == 0 ) {
      return Male ;
    } else if( str.compare( "Female" ) == 0 ) {
      return Female ;
    } else {
      throw UnknownGenderException( "gender couldn't be parsed" ) ;
    }
  }

}

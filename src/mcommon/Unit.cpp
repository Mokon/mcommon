/* Copyright (C) 2013-2014 David 'Mokon' Bond, All Rights Reserved */

#include "mcommon/Unit.hpp"

namespace mcommon {

  const std::string unitStrings[] = UNIT_STRINGS ;

  const std::map<std::string, Unit> unitMap = UNIT_MAP ;

  std::ostream& operator<<( std::ostream& os, const Unit& u ) {
    return os << unitStrings[u] ;
  }

  std::istream& operator>>( std::istream& is, Unit& u ) {
    char buf[255] ;
    is.getline(buf,255) ;
    
    auto i = unitMap.find( std::string(buf) ) ;
    if( i != unitMap.end( )) {
      u = i->second ;
    } else {
      throw UnknownUnitException( "couldn't parse unit" ) ;
    }

    return is ;
  }

}


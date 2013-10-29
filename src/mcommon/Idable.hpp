/* Copyright (C) 2013 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

#include <string>

namespace mcommon {

  typedef std::string Id ;

  class Idable {

    public:

      Idable( const Id id ) : id(id) {
      } ;

      Idable( ) = delete ;

      virtual ~Idable( ) = default ;

      Idable( const Idable& ) = default ;

      Idable& operator=( const Idable& ) = default ;

    private :

      const Id id ;

  } ;

}


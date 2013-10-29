/* Copyright (C) 2013 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

#include <utility>
#include <ostream>

#include "mcommon/Unit.hpp"

namespace mcommon {

  class Quantity {

    public:

      Quantity( const float mag, const Unit un ) ;

      float magnitude( ) const ;

      Unit unit( ) const ;

      Quantity convert( const Unit to ) const ;

      Quantity& operator+=( const Quantity& rhs ) ;

    private:

      std::pair<float, Unit> pair ;

      friend std::ostream& operator<<( std::ostream& out, const Quantity& o ) ;

  } ; 

}


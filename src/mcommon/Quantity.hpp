/* Copyright (C) 2013-2014 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <utility>
#include <ostream>

#include "mcommon/Unit.hpp"
#include "mcommon/Value.hpp"

namespace mcommon {

  class Quantity : public Value {

    public:

      Quantity( ) ;

      Quantity( const float mag, const Unit un ) ;

      float magnitude( ) const ;

      Unit unit( ) const ;

      Quantity convert( const Unit to ) const ;

      Quantity& operator+=( const Quantity& rhs ) ;

      Quantity operator *( const Quantity& rhs ) ;

      Quantity operator *( const float& rhs ) ;

      bool operator==( const Quantity& rhs ) const ;

    private:

      static constexpr float epsilon = 0.1 ;

      std::pair<float, Unit> pair ;

      virtual std::ostream& out( std::ostream& o ) const ;

  } ;

}


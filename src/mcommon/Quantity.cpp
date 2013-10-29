/* Copyright (C) 2013 David 'Mokon' Bond,  All Rights Reserved */

#include <stdexcept>

#include "mcommon/Quantity.hpp"

namespace mcommon {

  Quantity::Quantity( const float mag, const Unit un ) {
    pair = std::make_pair( mag, un ) ;
  }

  float Quantity::magnitude( ) const {
    return pair.first ;
  } 

  Unit Quantity::unit( ) const {
    return pair.second ;
  }

  Quantity Quantity::convert( const Unit to ) const {
    switch( unit() ) {
      case MILES: 
        switch( to ) {
          case MILES:
            return Quantity( magnitude(), to ) ;
          default:
            break ;
        }
      case INCHES: 
        switch( to ) {
          case INCHES:
            return Quantity( magnitude(), to ) ;
          default:
            break ;
        }
      case HOURS: 
        switch( to ) {
          case HOURS:
            return Quantity( magnitude(), to ) ;
          case MINUTES:
            return Quantity( magnitude()*60.0f, to ) ;
          case SECONDS:
            return Quantity( magnitude()*3600.0f, to ) ;
          default:
            break ;
        }
      case MINUTES: 
        switch( to ) {
          case HOURS:
            return Quantity( magnitude()/60.0f, to ) ;
          case MINUTES:
            return Quantity( magnitude(), to ) ;
          case SECONDS:
            return Quantity( magnitude()*60.0f, to ) ;
          default:
            break ;
        }
      case SECONDS: 
        switch( to ) {
          case HOURS:
            return Quantity( magnitude()*3600.0f, to ) ;
          case MINUTES:
            return Quantity( magnitude()/60.0f, to ) ;
          case SECONDS:
            return Quantity( magnitude(), to ) ;
          default:
            break ;
        }
      case MPH: 
        switch( to ) {
          case MPH:
            return Quantity( magnitude(), to ) ;
          case MPM:
            return Quantity( magnitude()*60.0f, to ) ;
          case MPS:
            return Quantity( magnitude()*3600.0f, to ) ;
          default:
            break ;
        }
      case MPM: 
        switch( to ) {
          case MPH:
            return Quantity( magnitude()/60.0f, to ) ;
          case MPM:
            return Quantity( magnitude(), to ) ;
          case MPS:
            return Quantity( magnitude()*60.0f, to ) ;
          default:
            break ;
        }
      case MPS: 
        switch( to ) {
          case MPH:
            return Quantity( magnitude()*3600.0f, to ) ;
          case MPM:
            return Quantity( magnitude()/60.0f, to ) ;
          case MPS:
            return Quantity( magnitude(), to ) ;
          default:
            break ;
        }
      case LBS: 
        switch( to ) {
          case LBS:
            return Quantity( magnitude(), to ) ;
          default:
            break ;
        }
      default:
        break ;
    }
    throw std::runtime_error( "invalid conversion" ) ;
  }

  Quantity& Quantity::operator+=( const Quantity& rhs ) {
    pair.first += rhs.convert(unit()).magnitude();
    return *this ;
  }

  std::ostream& operator<<( std::ostream& out, const Quantity& o ) {
    return out << o.magnitude( ) << " " << unitStrings[o.unit()] ;
  }

}


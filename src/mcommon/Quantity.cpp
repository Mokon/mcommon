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
      case METS: 
        switch( to ) {
          case METS:
            return Quantity( magnitude(), to ) ;
          default:
            break ;
        }
      case MILES: 
        switch( to ) {
          case MILES:
            return Quantity( magnitude(), to ) ;
          case KM:
            return Quantity( magnitude()*1.61, to ) ;
          default:
            break ;
        }
      case KM: 
        switch( to ) {
          case KM:
            return Quantity( magnitude(), to ) ;
          case MILES:
            return Quantity( magnitude()/1.61, to ) ;
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
      case YEARS: 
        switch( to ) {
          case YEARS:
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
      case KPH: 
        switch( to ) {
          case KPH:
            return Quantity( magnitude(), to ) ;
          case MPH:
            return Quantity( magnitude()/1.61f, to ) ;
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
          case KPH:
            return Quantity( magnitude()*1.61f, to ) ;
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
          case KG:
            return Quantity( magnitude()*0.454, to ) ;
          default:
            break ;
        }
      case KG: 
        switch( to ) {
          case KG:
            return Quantity( magnitude(), to ) ;
          case LBS:
            return Quantity( magnitude()/0.454, to ) ;
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


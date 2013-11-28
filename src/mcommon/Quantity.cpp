/* Copyright (C) 2013 David 'Mokon' Bond,  All Rights Reserved */

#include <cmath>
#include <stdexcept>

#include "mcommon/Quantity.hpp"

namespace mcommon {

  Quantity::Quantity( ) {
    pair = std::make_pair( 0, UNKNOWN_UNIT ) ;
  }

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
      case CM:
        switch( to ) {
          case CM:
            return Quantity( magnitude(), to ) ;
          case INCHES:
            return Quantity( magnitude()/2.54, to ) ;
          default:
            break ;
        }
      case INCHES:
        switch( to ) {
          case INCHES:
            return Quantity( magnitude(), to ) ;
          case CM:
            return Quantity( magnitude()*2.54, to ) ;
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

  Quantity Quantity::operator *( const Quantity& rhs ) {
    Quantity ret(*this);
    ret.pair.first *= rhs.convert(unit()).magnitude() ;
    return ret ;
  }

  Quantity Quantity::operator *( const float& rhs ) {
    Quantity ret(*this);
    ret.pair.first *= rhs ;
    return ret ;
  }

  std::ostream& Quantity::out( std::ostream& o ) const {
    switch(unit()) {
      case HOURS:
      case MINUTES:
      case SECONDS:
        {
          Quantity s( std::round(std::fmod( convert(SECONDS).magnitude(), 60)), SECONDS) ;
          Quantity m( std::trunc(convert(MINUTES).magnitude()), MINUTES ) ;
          Quantity h( std::trunc(convert(HOURS).magnitude()), HOURS ) ;
          if( h.magnitude() != 0 ) {
            o << h.magnitude( ) << " " << unitStrings[h.unit()] << " " ;
          }
          if( m.magnitude() != 0 ) {
            o << m.magnitude( ) << " " << unitStrings[m.unit()] << " " ;
          }
          if( s.magnitude() != 0 ) {
            o << s.magnitude( ) << " " << unitStrings[s.unit()] ;
          }
          return o ;
        }
      case NONE:
        return o << magnitude( ) ;
      default:
        return o << magnitude( ) << " " << unitStrings[unit()] ;
    }
  }

}


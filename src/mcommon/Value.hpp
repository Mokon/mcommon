/* Copyright (C) 2013 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

namespace mcommon {

  class Value {

    public:

      Value( ) = default ;

      virtual ~Value( ) = default ;

      Value( const Value& ) = default ;

      Value& operator=( const Value& ) = default ;

      friend std::ostream& operator<<( std::ostream& o, const Value& v ) {
        return v.out( o ) ;
      }

    private:

      virtual std::ostream& out( std::ostream& o ) const { return o ; } ;

  } ;

}


/* Copyright (C) 2012-2014 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <mcommon/pubsub/Publisher.hpp>

/*
 * A publisher subscriber implementation.
 */
namespace mcommon {

  template <class Subscription> class Subscriber {

    public:

      Subscriber( ) = default ;

      virtual ~Subscriber( ) = default ;
      
      ~Subscriber( const ~Subscriber& ) = default ;

      ~Subscriber& operator=( const ~Subscriber& ) = default ;

      virtual void consume( std::shared_ptr<Publisher<Subscription> > p,
          std::shared_ptr<Subscription> s ) = 0 ;

  } ;

}


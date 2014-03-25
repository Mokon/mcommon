/* Copyright (C) 2012-2014 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <list>
#include <stdio.h>
#include <memory>

namespace mcommon {

  template <class Subscription> class Subscriber ;

  /*
   * A publisher subscriber implementation.
   */
  template <class Subscription> class Publisher {

    public:

      Publisher( ) = default ;

      virtual ~Publisher( ) = default ;

      Publisher( const Publisher& ) = default ;

      Publisher& operator=( const Publisher& ) = default ;

      void subscribe( std::shared_ptr<Subscriber<Subscription>> s) {
        subscribers.push_back(s) ;
      } ;

      void unsubscribe( std::shared_ptr<Subscriber<Subscription>> s) {
        subscribers.remove(s) ;
      } ;

      void publish( std::shared_ptr<Subscription> s ) {
        typename std::list<std::shared_ptr<Subscriber<Subscription> > >::iterator p ;
        typename std::list<std::shared_ptr<Subscriber<Subscription> > >::iterator pcur ;
        for( p = subscribers.begin() ; p != subscribers.end() ; ) {
          pcur = p ;
          ++p ;
          (*pcur)->consume( this, s ) ;
        }
      } ;

      void clearSubscribers( ) {
        subscribers.clear( ) ;
      }

    private:

      /* Since we always iterate this list and we want fast insertions a linked
       * list works best. */
      std::list<std::shared_ptr<Subscriber<Subscription> > > subscribers ;

  } ;

}


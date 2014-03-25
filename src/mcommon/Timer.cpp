/* Copyright (C) 2013-2014 David 'Mokon' Bond, All Rights Reserved */

#include <boost/asio/signal_set.hpp>

#include "mcommon/Log.hpp"
#include "mcommon/Timer.hpp"

namespace mcommon {

  Timer::Timer( ) : timer(io), unlimited(true), count(0), milliseconds(0) {
  } 

  Timer::~Timer( ) {
    stop( ) ;
  } 

  void Timer::start( int milliseconds ) {
    unlimited = true ;
    this->milliseconds = milliseconds ;
    count = 0 ;
    timer.expires_from_now( boost::posix_time::millisec(milliseconds) ) ;
    timer.async_wait( boost::bind( &Timer::callback, this ) ) ;
  }

  void Timer::start( int milliseconds, unsigned int count ) {
    unlimited = false ;
    this->milliseconds = milliseconds ;
    this->count = count ;
    timer.expires_from_now( boost::posix_time::millisec(milliseconds) ) ;
    timer.async_wait( boost::bind( &Timer::callback, this ) ) ;
  }

  void Timer::connect( boost::function<void()> fp ) {
    this->fp = fp ;
  }

  void Timer::callback( ) {
    if( fp ) {
      fp( ) ;
    }
    if( unlimited || --count > 0 ) {
      timer.expires_from_now( boost::posix_time::millisec(milliseconds) ) ;
      timer.async_wait( boost::bind( &Timer::callback, this ) ) ;
    }
  }

  void Timer::stop( ) {
    timer.cancel( ) ;
  }

  int Timer::run( ) {
    running = true ;
    while( running ) {
      io.run( ) ;
    }
    return EXIT_SUCCESS ;
  }

  void Timer::stopRun( const boost::system::error_code& ec, int sig ) {
    boost::ignore_unused_variable_warning( ec ) ; 
    boost::ignore_unused_variable_warning( sig ) ; 
    running = false ;
    io.stop( ) ;
  }

  boost::asio::io_service Timer::io ;

  boost::asio::signal_set Timer::sigs(io, SIGINT, SIGTERM);

  bool Timer::running ;

  void Timer::addSignalHandler( std::function<void(                           
        const boost::system::error_code& ec, int signal_number)>handler ) {
    sigs.async_wait(handler) ;
  }

}


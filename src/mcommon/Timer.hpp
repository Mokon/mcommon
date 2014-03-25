/* Copyright (C) 2013-2014 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/function.hpp>

namespace mcommon {

  class Timer {

    public:

      /* Constructs a timer not running. */
      Timer( ) ;

      /* Destructs the timer. */
      virtual ~Timer( ) ;

      /* Starts the timer running for the given amount of time and an unlimited
       * number of times. */
      void start( int milliseconds ) ;

      /* Starts the timer running for the given amount of time and count times. */
      void start( int milliseconds, unsigned int count ) ;

      /* Connects a callback function pointer. */
      void connect( boost::function<void()> fp ) ;

      /* Calls the callback function pointer. */
      void callback( ) ;

      /* Stops the currently running timer. */
      void stop( ) ;

      /* A static timer loop that runs all timers. */
      static int run( ) ;

      /* Stops the timer loop. */
      static void stopRun( const boost::system::error_code& ec, int sig ) ;

      /* Adds a signal handler to the signals. */
      static void addSignalHandler( std::function<void(
            const boost::system::error_code& ec, int signal_number)> handler ) ;

    private:

      /* TODO we should really not have this be a global service */
      /* An io_service for the timer class. */
      static boost::asio::io_service io ;

      /* The underlying timer implementation. */
      boost::asio::deadline_timer timer ;

      /* The function pointer to be called on timer expiration. */
      boost::function<void()> fp ;

      /* Whether when start is called the callback will be called and unlimited
       * number of times or a limited number of times. */
      bool unlimited ;

      /* If unlimited == false then this value equals the number of times
       * remaining to call the callback on timeout. */
      unsigned int count ;

      /* The number of milliseconds for the current timer. */
      int milliseconds ;

      /* A boolean flag on whether the ioservice should be running. */
      static bool running ;

      /* signal set for sigint and sigterm */
      static boost::asio::signal_set sigs ;

  } ;

}


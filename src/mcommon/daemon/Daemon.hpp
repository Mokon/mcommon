/* Copyright (C) 2013-2016 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <mcommon/Exception.hpp>
#include <mcommon/Timer.hpp>

namespace mcommon {

class Daemon
{

  public:

    enum State {
        init,
        starting,
        running,
        stopping,
        stopped
    };

    DEFINE_EXCEPTION_CLASS(StateException);

    Daemon() = delete;

    Daemon(int argc, char* argv[]);

    virtual ~Daemon();

    Daemon(const Daemon&) = delete;

    Daemon& operator=(const Daemon&) = delete;

    Daemon(Daemon&&) = delete;

    Daemon& operator=(Daemon&&) = delete;

    virtual void start();

    virtual void join();

    virtual void stop();

    virtual void stop(const boost::system::error_code& ec, int sig);

    virtual void run() = 0;

    void exec();

    int getStatus();

    void setStatus(int newStatus);

    void changeState(State expectedState, State newState);

    bool isStopping();

  private:

    int status;

    State state = init;

};

}

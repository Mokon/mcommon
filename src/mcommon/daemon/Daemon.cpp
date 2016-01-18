/* Copyright (C) 2012-2016 David 'Mokon' Bond, All Rights Reserved */

#include <config.h>
#include <functional>
#include <mcommon/daemon/Daemon.hpp>
#include <mcommon/Log.hpp>
#include <boost/concept_check.hpp>

namespace mcommon {

Daemon::Daemon(int argc, char* argv[])
    : status(EXIT_SUCCESS)
    , state(init)
{
    try {
        mcommon::log::init(argc, argv);

        LOG(INFO) << PACKAGE_NAME << " " << PACKAGE_COPYRIGHT << std::endl;

        mcommon::Timer::addSignalHandler(
            std::bind(static_cast<void(Daemon::*)()>(&Daemon::stop), this));
    } catch(const std::exception& ex) {
        LOG(ERROR) << ex.what() << std::endl;
        status = EXIT_FAILURE;
    } catch (...) {
        LOG(ERROR) << "Caught thrown" << std::endl;
        status = EXIT_FAILURE;
    }
}

Daemon::~Daemon( )
{
}

void
Daemon::changeState(State expectedState, State newState)
{
    if (expectedState != state) {
        throw StateException("illegal state");
    }

    state = newState;
}

void Daemon::start()
{
    /* TODO global timer service is ugly. */
    mcommon::Timer::startRun();
    changeState(init, starting);
}

void Daemon::stop()
{
    mcommon::Timer::stopRun();
    changeState(running, stopping);
}

void Daemon::stop(const boost::system::error_code& ec, int sig)
{
    boost::ignore_unused_variable_warning(ec);
    boost::ignore_unused_variable_warning(sig);
    stop();
}

void Daemon::join()
{
    if (state == running) {
        stop();
    }
    mcommon::Timer::join();
    changeState(stopping, stopped);
}

int Daemon::getStatus()
{
    return status;
}

void Daemon::setStatus(int newStatus)
{
    status = newStatus;
}

void Daemon::exec()
{
    if (getStatus() == EXIT_SUCCESS) {
        start();
        changeState(starting, running);
        run();
        join();
    }
}

bool
Daemon::isStopping()
{
  return state == stopping;
}

}

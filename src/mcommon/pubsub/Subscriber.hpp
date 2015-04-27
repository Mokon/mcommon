/* Copyright (C) 2012-2015 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <mcommon/pubsub/Publisher.hpp>

namespace mcommon {

template <class Subscription> class Subscriber
{

  public:

    Subscriber() = default;

    virtual ~Subscriber() = default;

    Subscriber(const Subscriber&) = default;

    Subscriber& operator=(const Subscriber&) = default;

    Subscriber(Subscriber&&) = default;

    Subscriber& operator=(Subscriber&&) = default;

    virtual void consume(const std::shared_ptr<Publisher<Subscription>>& p,
                         const std::shared_ptr<Subscription>& s) = 0;

};

}

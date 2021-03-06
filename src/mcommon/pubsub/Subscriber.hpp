/* Copyright (C) 2013-2016 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <mcommon/pubsub/Publisher.hpp>

namespace mcommon {

template <class Subscription> class Subscriber
{

  public:

    Subscriber() = default;

    virtual ~Subscriber() = default;

    explicit Subscriber(const Subscriber&) = default;

    Subscriber& operator=(const Subscriber&) = default;

    explicit Subscriber(Subscriber&&) = default;

    Subscriber& operator=(Subscriber&&) = default;

    virtual void consume(const std::shared_ptr<Publisher<Subscription>>& p,
                         const std::shared_ptr<Subscription>& s) = 0;

};

}

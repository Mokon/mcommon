/* Copyright (C) 2013-2016 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <list>
#include <stdio.h>
#include <memory>

namespace mcommon {

template <class Subscription> class Subscriber;

template <class Subscription> class Publisher
{

  public:

    Publisher() = default;

    virtual ~Publisher() = default;

    Publisher(const Publisher&) = default;

    Publisher& operator=(const Publisher&) = default;

    Publisher(Publisher&&) = default;

    Publisher& operator=(Publisher&&) = default;

    void subscribe(const std::shared_ptr<Subscriber<Subscription>>& s)
    {
        subscribers.push_back(s);
    }

    void unsubscribe(const std::shared_ptr<Subscriber<Subscription>>& s)
    {
        subscribers.remove(s);
    }

    void publish(const std::shared_ptr<Subscription>& s) 
    {
        for(auto p = subscribers.begin(); p != subscribers.end();) {
            auto pcur = p;
            ++p;
            (*pcur)->consume(this, s);
        }
    }

    void clearSubscribers()
    {
        subscribers.clear();
    }

  private:

    std::list<std::shared_ptr<Subscriber<Subscription>>> subscribers;

};

}

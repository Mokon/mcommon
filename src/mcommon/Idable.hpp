/* Copyright (C) 2013-2015 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <string>

namespace mcommon {

using Id = std::string;

class Idable
{

  public:

    Idable(const Id& id)
        : id(id)
    {
    }

    Idable() = delete;

    virtual ~Idable() = default;

    Idable(const Idable&) = default;

    Idable& operator=(const Idable&) = default;

    Idable(Idable&&) = default;

    Idable& operator=(Idable&&) = default;

    const Id getId() const
    {
        return id;
    }

  private:

    const Id id;

};

}

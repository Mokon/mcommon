/* Copyright (C) 2013-2015 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <mcommon/Displayable.hpp>

namespace mcommon {

class Value
    : public Displayable
{

  public:

    Value() = default;

    virtual ~Value() = default;

    Value(const Value&) = default;

    Value& operator=(const Value&) = default;

    Value(Value&&) = delete;

    Value& operator=(Value&&) = delete;

  protected:

    virtual std::ostream& out(std::ostream& o) const override
    {
        return o;
    }

};

}

/* Copyright (C) 2013-2015 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <iostream>
#include <sstream>

namespace mcommon {

class Displayable
{
  public:

    Displayable() = default;

    virtual ~Displayable() = default;

    Displayable(Displayable&&) = default;

    Displayable& operator=(Displayable&&) = default;

    Displayable(const Displayable&) = default;

    Displayable& operator=(const Displayable&) = default;

    friend std::ostream& operator<<(std::ostream& strm, const Displayable& o)
    {
        return strm << o.display();
    }

    virtual std::string display() const
    {
        std::stringstream stm;
        out(stm);
        return stm.str();
    }

  protected:

    virtual std::ostream& out(std::ostream& stm) const = 0;

};

}

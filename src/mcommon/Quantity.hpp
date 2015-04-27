/* Copyright (C) 2013-2015 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <mcommon/Unit.hpp>
#include <mcommon/Value.hpp>
#include <ostream>
#include <utility>

namespace mcommon {

class Quantity
    : public Value
{

  public:

    Quantity();

    Quantity(const long double mag, const Unit un);

    virtual ~Quantity() = default;

    Quantity(const Quantity&) = default;

    Quantity& operator=(const Quantity&) = default;

    Quantity(Quantity&&) = default;

    Quantity& operator=(Quantity&&) = default;

    long double magnitude() const;

    Unit unit() const;

    Quantity convert(const Unit to) const;

    Quantity& operator+=(const Quantity& rhs);

    Quantity operator*(const Quantity& rhs);

    Quantity operator*(const long double& rhs);

    bool operator==(const Quantity& rhs) const;

  protected:
    
    virtual std::ostream& out(std::ostream& o) const override;

  private:

    static constexpr long double epsilon = 0.1l;

    std::pair<long double, Unit> pair;

};

}

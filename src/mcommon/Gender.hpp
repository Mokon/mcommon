/* Copyright (C) 2013-2016 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <iostream>
#include <mcommon/Exception.hpp>
#include <string>
#include <string.h>

namespace mcommon {

DEFINE_EXCEPTION_CLASS(UnknownGenderException);

enum Gender {
    Male,
    Female,
    GENDER_MAX
};

std::ostream& operator<<(std::ostream& os, const Gender& g);

std::istream& operator>>(std::istream& is, Gender& g);

Gender toGender(const std::string& str);

}

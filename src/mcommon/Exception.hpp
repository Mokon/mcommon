/* Copyright (C) 2013-2016 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <stdexcept>

namespace mcommon {

#define DEFINE_EXCEPTION_CLASS(ClassName) \
class ClassName : public std::runtime_error { \
  public: \
    ClassName (const std::string& err) \
        : runtime_error(err) \
    { \
    } \
}

}

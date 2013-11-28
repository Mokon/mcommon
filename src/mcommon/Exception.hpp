/* Copyright (C) 2013 David 'Mokon' Bond,  All Rights Reserved */

#pragma once

#include <stdexcept>

namespace mcommon {

#define DEFINE_EXCEPTION_CLASS( Name ) \
  class Name : public std::runtime_error { \
    public: \
            Name ( const std::string& err ) : runtime_error(err) { \
            } \
  }

}


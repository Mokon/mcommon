# Copyright (C) 2013-2014 David 'Mokon' Bond, All Rights Reserved

SRC_DIR = ../src
AM_LIBTOOLFLAGS= --silent

if DEBUG
  AM_CXXFLAGS = -DDEBUG -g -O0 -rdynamic -fstack-protector-all -static -pg
  AM_LDFLAGS = -static -pg
else
  AM_CXXFLAGS = -g0 -O3
  AM_LDFLAGS =
endif # DEBUG

AM_CXXFLAGS += -Wall -Wextra -std=c++11 -pedantic -Werror
AM_CXXFLAGS += -I${SRC_DIR} -I../../mcommon/src


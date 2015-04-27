# Copyright (C) 2013-2015 David 'Mokon' Bond, All Rights Reserved

SRC_DIR = ../src
AM_LIBTOOLFLAGS = --silent

if DEBUG
AM_CXXFLAGS = -DDEBUG -g -O0 -fstack-protector-all -static -pg
AM_LDFLAGS = -static -pg
else
AM_CXXFLAGS = -g0 -O3
AM_LDFLAGS =
endif # DEBUG

AM_CXXFLAGS += -Wall -Wextra -std=c++1y -pedantic -Werror -Weffc++
AM_CXXFLAGS += -Wpedantic -pedantic-errors -Wundef
AM_CXXFLAGS += -Wshadow -Wstrict-aliasing -Woverloaded-virtual
AM_CXXFLAGS += -Wconversion -Wsign-compare -Wsign-conversion
AM_CXXFLAGS += -Wdeprecated -Wzero-as-null-pointer-constant
AM_CXXFLAGS += -Wold-style-cast -Wcast-qual -Wcast-align
AM_CXXFLAGS += -Wunused-parameter -Wunused
AM_CXXFLAGS += -Wchar-subscripts -Wcomment -Winit-self
AM_CXXFLAGS += -Wtrampolines -Wlogical-op -Wmissing-declarations
AM_CXXFLAGS += -Wmissing-field-initializers -Wparentheses -Wformat=2
AM_CXXFLAGS += -I${SRC_DIR} -I../../mcommon/src -I../mcommon/src

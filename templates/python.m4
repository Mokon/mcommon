# Copyright (C) 2013-2014 David 'Mokon' Bond, All Rights Reserved

###############################################################################
# First, any configure.ac which includes this wants Python. Let's assume we have
# the configure.m4 and define a PYTHON feature.
###############################################################################
M_DEFINE([python],[PYTHON])

###############################################################################
# Now the following configures the build env. for boost python linkage.
###############################################################################
AM_PATH_PYTHON
AC_ARG_VAR([PYTHON_INCLUDE],
           [Include flags for python, bypassing python-config])
AC_ARG_VAR([PYTHON_CONFIG], [Path to python-config])
AS_IF([test -z "$PYTHON_INCLUDE"], [
  AS_IF([test -z "$PYTHON_CONFIG"], [
    AC_PATH_PROGS([PYTHON_CONFIG],
                  [python$PYTHON_VERSION-config python-config],
                  [no],
                  [`dirname $PYTHON`])
    AS_IF([test "$PYTHON_CONFIG" = no],
          [AC_MSG_ERROR([cannot find python-config for $PYTHON.])])
  ])
  AC_MSG_CHECKING([python include flags])
  PYTHON_INCLUDE=`$PYTHON_CONFIG --includes`
  AC_MSG_RESULT([$PYTHON_INCLUDE])
])

AC_ARG_VAR([PYTHON_LD], [Linker flags for python, bypassing python-config])
AS_IF([test -z "$PYTHON_LD"], [
  AS_IF([test -z "$PYTHON_CONFIG"], [
    AC_PATH_PROGS([PYTHON_CONFIG],
                  [python$PYTHON_VERSION-config python-config],
                  [no],
                  [`dirname $PYTHON`])
    AS_IF([test "$PYTHON_CONFIG" = no],
          [AC_MSG_ERROR([cannot find python-config for $PYTHON.])])
  ])
  AC_MSG_CHECKING([python linker flags])
  PYTHON_LD=`$PYTHON_CONFIG --ldflags`

  AC_MSG_RESULT([$PYTHON_LD])
])


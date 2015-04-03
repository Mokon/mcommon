# Copyright (C) 2013-2014 David 'Mokon' Bond, All Rights Reserved

###############################################################################
# This macro allows one to quickly create a configure feature. This feature can
# be enabled in the configure script with --enable-feature-name or disabled with
# --disable-feature name. In automake files one can also use a if FEATURE to do
# things conditionally based on it. Finally this introduces a #define in the 
# config.h file for this feature. E.g:
#   If you put:
#     M_DEFINE([db],[DB])
#   In you configure.ac you can use
#     if DB
#   In your Makefile.am and you can use:
#     #ifdef DB
#   In you source files that include config.h
##############################################################################
AC_DEFUN([M_DEFINE],
[
  AC_ARG_ENABLE([$1],
    [  --enable-$1    Turn on feature $2.],
    [case "${enableval}" in
      yes) $1=true ;;
      no)  $1=false ;;
      *) AC_MSG_ERROR([bad value ${enableval} for --enable-$1]) ;;
    esac],[$1=true])
  AM_CONDITIONAL([$2], [test x$$1 = xtrue])
  if test x$$1 = xtrue ; then
    AC_MSG_NOTICE([Defining $1])
    AC_DEFINE([$2], [1], [Include the $2. ])
  fi
])

##############################################################################
# This macro is similar to the M_DEFINE macro but it does not add anything to
# the config.h file. This is meant for programs which need to be enabled by
# the configure script.
##############################################################################
AC_DEFUN([M_PROG],
[
  AC_ARG_ENABLE([$1],
    [  --enable-$1    Turn on feature $2.],
    [case "${enableval}" in
      yes) $1=true ;;
      no)  $1=false ;;
      *) AC_MSG_ERROR([bad value ${enableval} for --enable-$1]) ;;
    esac],[$1=true])
  AM_CONDITIONAL([$2], [test x$$1 = xtrue])
])

##############################################################################
# This macro is used to add the required library linkage into a given program.
# Thus if you have a program called mfin which needs to link to pthread you add
# this:
#   M_CHECK_LIB([pthread],[mfin],[])
# And then after you are done with any more links that need to be made to mfin
# you add a:
#   AC_SUBST([mfin_LDADD])
# This forms the mfin_LDADD variable for use in the Makefiles for linkage
# specific to the given program. This is nice if you have multiple programs
# being built by a single project each which need seperate libs for linkage.
# The last variable is other libs to link with.
##############################################################################
AC_DEFUN([M_CHECK_LIB],
[
  AC_MSG_NOTICE([m check lib $1])
  AC_CHECK_LIB([$1],[main],
    [$2_LDADD="$$2_LDADD -l$1"          
      AC_DEFINE([HAVE_LIB$1], [1], [Define if you have lib$1])],
    [AC_MSG_WARN([$1 library not found $2_LDADD ${2}_LDADD])],
    [$3])
])

##############################################################################
# This macro defines a copy right string for the package. The arguments are
# whom owns the copyright and copyright date.
##############################################################################
AC_DEFUN([M_COPYRIGHT_PROPRIETARY],
[
  AC_COPYRIGHT([Copyright (C) $2 $1])
  AC_DEFINE([PACKAGE_COPYRIGHT],
          ["Copyright (C) $2 $1, All Rights Reserved"],
          [Copyright String for the Package])
])

AC_DEFUN([M_PROG_DEP],[
  AC_MSG_NOTICE([next 2 is $1 and 3 is $2])
  M_CHECK_LIB([$1],m4_defn([prog]),[$2])])
AC_DEFUN([M_PROG_DEPS],
[
  define([prog],[$1])
  AC_MSG_NOTICE([2 is $2 and 3 is $3])
  m4_map([M_PROG_DEP],[$2])
  AC_SUBST([$1_LDADD])
])
# m4_foreach_w([lib], [$2],[M_CHECK_LIB(m4_defn([lib]),[$1])])

###############################################################################
# Provide a debug flag which prevents stripping of debugging information and
# optimizations
###############################################################################
M_DEFINE([debug], [DEBUG], [DEBUG])

if test x$debug = xfalse ; then
AC_DEFINE([GOOGLE_STRIP_LOG], [1], [Strip Logging Messages from Release.])
fi

###############################################################################
# Optional for man pages.
###############################################################################
AC_CHECK_PROG([has_help2man],[help2man],[true],[false])
AM_CONDITIONAL([HAS_HELP2MAN], [test x$has_help2man = xtrue])

###############################################################################
# Some misc. calls that should always be used.
###############################################################################
AM_INIT_AUTOMAKE([-Wall foreign subdir-objects])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_USE_SYSTEM_EXTENSIONS
AC_PROG_LIBTOOL
#LC_INIT

AC_CONFIG_FILES([
  Makefile
  object/Makefile
  test/Makefile
  doc/Makefile
])


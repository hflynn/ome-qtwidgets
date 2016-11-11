# #%L
# OME C++ libraries (cmake build infrastructure)
# %%
# Copyright © 2006 - 2016 Open Microscopy Environment:
#   - Massachusetts Institute of Technology
#   - National Institutes of Health
#   - University of Dundee
#   - Board of Regents of the University of Wisconsin-Madison
#   - Glencoe Software, Inc.
# %%
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# The views and conclusions contained in the software and documentation are
# those of the authors and should not be interpreted as representing official
# policies, either expressed or implied, of any organization.
# #L%

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost 1.54 REQUIRED
             COMPONENTS date_time filesystem system iostreams
                        log log_setup program_options regex thread)

include(CheckIncludeFileCXX)
include(CheckCXXSourceCompiles)

set(CMAKE_REQUIRED_DEFINITIONS_SAVE ${CMAKE_REQUIRED_DEFINITIONS})
set(CMAKE_REQUIRED_DEFINITIONS ${CMAKE_REQUIRED_DEFINITIONS} -DBOOST_ALL_DYN_LINK -DBOOST_ALL_NO_LIB)
set(CMAKE_REQUIRED_INCLUDES_SAVE ${CMAKE_REQUIRED_INCLUDES})
set(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} ${Boost_INCLUDE_DIRS})

# boost::variant/boost::mpl list size limits
check_cxx_source_compiles("
#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/mpl/vector.hpp>

#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/get.hpp>
#include <boost/variant/variant.hpp>

struct s1 {};
struct s2 {};
struct s3 {};
struct s4 {};
struct s5 {};
struct s6 {};
struct s7 {};
struct s8 {};
struct s9 {};
struct s10 {};
struct s11 {};
struct s12 {};
struct s13 {};
struct s14 {};
struct s15 {};
struct s16 {};
struct s17 {};
struct s18 {};
struct s19 {};
struct s21 {};
struct s20 {};
struct s22 {};
struct s23 {};
struct s24 {};
struct s25 {};
struct s26 {};

typedef boost::mpl::vector<s1, s2, s3, s4, s5, s6, s7, s8, s9> v1;
typedef boost::mpl::vector<s10, s11, s12, s13, s14, s15, s16, s17, s18> v2;
typedef boost::mpl::vector<s19, s20, s21, s22, s23, s24, s25, s26> v3;

typedef boost::mpl::joint_view<v1, v2>::type v4;
typedef boost::mpl::joint_view<v3, v4>::type v5;

typedef boost::mpl::vector<> empty_types;

typedef boost::mpl::insert_range<empty_types, boost::mpl::end<empty_types>::type, v4>::type type_list;

typedef boost::make_variant_over<type_list>::type vt;

void
set (const vt& value)
{
  vt v = value;
}

int main() {
  set(s5());
  set(s25());
}"
OME_VARIANT_LIMIT)

set(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES_SAVE})
set(CMAKE_REQUIRED_DEFINITIONS ${CMAKE_REQUIRED_DEFINITIONS_SAVE})

/*
    rexgen - a tool to create words based on regular expressions
    Copyright (C) 2012-2019  Jan Starke <jan.starke@outofbed.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
    more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin St, Fifth Floor, Boston, MA 02110, USA
*/

#include <catch2/catch.hpp>
#include <librexgen/catch2/RexgenGenerator.h>
#include <boost/regex.hpp>

TEST_CASE("generating some values based on regexes", "hello[0-9]") {

  constexpr auto test_regex = "hel(?i:lo)[0-9]";
  boost::regex _re(test_regex);

  SECTION("Nice UX") {
    auto i = GENERATE(take(100, rexgen::catch2::regex(test_regex)));
    REQUIRE(boost::regex_match(i, _re));
  }
}
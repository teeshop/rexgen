/*
    rexgen - a tool to create words based on regular expressions
    Copyright (C) 2012-2017  Jan Starke <jan.starke@outofbed.org>

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

#include <librexgen/regex/regex.h>
#include <librexgen/iterator/FastIteratorPermuter.h>
#include <set>
namespace rexgen {
  FastIteratorPermuter::FastIteratorPermuter(const Regex& re, IteratorState& is, unsigned int occurs)
          : IteratorContainer() {
    assert(occurs > 0);
    for (unsigned int n = 0; n < occurs; ++n) {
      auto iter = re.singleIterator(is);
      iter->next();
      addChild(std::move(iter));
    }

    state = resetted;
  }

  void FastIteratorPermuter::value(SimpleString *dst) const {
    for (const std::unique_ptr<Iterator>& i : iterators) {
      i->value(dst);
    }
  }

  bool FastIteratorPermuter::next() {
    ENTER_METHOD;

    /* special case handling for resetted state */
    if (state == resetted) {
      state = usable;
      RETURN(true);
    }

    for (std::unique_ptr<Iterator>& i : iterators) {
      if (i->next()) {
        return true;
      }
    }
    return false;
  }
}
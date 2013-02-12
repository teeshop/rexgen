/*
    Copyright (c) 2012, Jan Starke <jan.starke@outofbed.org>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
        * Neither the name of the <organization> nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY Jan Starke <jan.starke@outofbed.org> ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL Jan Starke <jan.starke@outofbed.org> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef QUANTIFIER_H
#define QUANTIFIER_H

class Quantifier
{

public:
  Quantifier() : min(1), max(1) {}
  Quantifier(unsigned int _min, unsigned int _max) : min(_min), max(_max) {}
  Quantifier ( const Quantifier& other ): min(other.min), max(other.max) {}
  virtual ~Quantifier() {}
  virtual Quantifier& operator= ( const Quantifier& other ) {
    this->min = other.getMin();
    this->max = other.getMax();
    return *this;
  }
  virtual bool operator== ( const Quantifier& other ) const {
    return (this->min == other.min) && (this->max == other.max);
  }
  
  inline unsigned int getMin() const { return min; }
  inline unsigned int getMax() const { return max; }
  
  inline void setMin(unsigned _min) { min = _min; }
  inline void setMax(unsigned _max) { max = _max; }
  
public:
  unsigned int min;
  unsigned int max;
};

#endif // QUANTIFIER_H
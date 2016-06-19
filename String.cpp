/*
 * Copyright (c) 2016, Mattijs Korpershoek
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "String.hpp"

#include <stdexcept>
#include <sstream>

String::String() : mChars()
{}

String::String(const char *const chars) : mChars()
{
    for (const char *c = chars; c != NULL && *c != '\0'; c++) {
        mChars.push_back(*c);
    }
}

String::String(const String &other) : mChars(other.mChars)
{}

String::String(String &&other) : mChars(std::move(other.mChars))
{}

String::~String()
{}

bool String::operator==(const String &other) const
{
    return mChars == other.mChars;
}

bool String::operator!=(const String &other) const
{
    return mChars != other.mChars;
}

void String::operator+=(const String &other)
{
    for (auto c = other.mChars.begin(); c != other.mChars.end(); c++) {
        mChars.push_back(*c);
    }
}

String::const_iterator String::begin()
{
    return mChars.begin();
}

String::const_iterator String::end()
{
    return mChars.end();
}

int String::toInteger() throw(std::invalid_argument)
{
    std::stringstream stream;
    int result;

    for (auto c = mChars.begin(); c != mChars.end(); c++) {
        stream << *c;
    }

    stream >> result;
    if (stream.fail() || stream.bad()) {
        throw std::invalid_argument("This string is not an integer");
    }

    return result;
}

void String::clear()
{
    mChars.clear();
}
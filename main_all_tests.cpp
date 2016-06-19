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
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "external/Catch/include/catch.hpp"

#include "String.hpp"

TEST_CASE("String comparison", "[string]")
{
    String hello("hello, world");
    String hello_bis("hello, world");
    String empty;
    String empty_bis;
    char *my_test_str = "goodbye, world";
    String goodbye(my_test_str);

    REQUIRE(hello == hello_bis);
    REQUIRE(empty == empty_bis);
    REQUIRE(hello != empty);
    REQUIRE(goodbye != hello);
}

TEST_CASE("String emptyness", "[string]")
{
    String hello("hello, world");
    String empty;
    REQUIRE(hello != empty);

    hello.clear();
    REQUIRE(hello == empty);
}

TEST_CASE("String append", "[string]")
{
    String hello("hello");
    String helloAppendEmpty("hello");
    String world(", world");
    String helloWorld("hello, world");
    String emptyAppendHello;
    String empty;

    emptyAppendHello += hello;
    REQUIRE(emptyAppendHello == hello);

    helloAppendEmpty += empty;
    REQUIRE(hello == helloAppendEmpty);

    hello += world;
    REQUIRE(hello == helloWorld);
}

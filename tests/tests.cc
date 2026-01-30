// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Georges Durand                   Environment : ubuntu:bionic               //
//  Date ......: 2024/09/02                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"
/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "solution.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("RotateRight function", "[rotate_right]") {
  SECTION("Empty vector") {
    std::vector<int> input = {};
    REQUIRE((RotateRight(input, 3) == std::vector<int>{}));
  }

  SECTION("Single element vector") {
    std::vector<int> input = {1};
    REQUIRE((RotateRight(input, 16) == std::vector<int>{1}));
  }
  SECTION("Simple case") {
    std::vector<int> input = {1, 2, 3};
    REQUIRE((RotateRight(input, 2) == std::vector<int>{2, 3, 1}));
  }

  SECTION("Normal case") {
    std::vector<int> input = {22, 13, 3, 4, 16};
    REQUIRE((RotateRight(input, 2) == std::vector<int>{4, 16, 22, 13, 3}));
  }
  SECTION("Larger case") {
    std::vector<int> input = {22, 13, 3, 4, 16, 6, 7, 32, 9, 10};
    REQUIRE((RotateRight(input, 3) ==
             std::vector<int>{32, 9, 10, 22, 13, 3, 4, 16, 6, 7}));
  }
  SECTION("Rotation larger than vector size") {
    std::vector<int> input = {22, 13, 3, 4};
    REQUIRE((RotateRight(input, 6) == std::vector<int>{3, 4, 22, 13}));
  }
}

TEST_CASE("RotateChunks function", "[rotate_chunks]") {
  SECTION("Empty vector") {
    std::vector<int> input = {};
    REQUIRE((RotateChunks(input, 3, 1) == std::vector<int>{}));
  }

  SECTION("Chunk size of 1") {
    std::vector<int> input = {22, 13, 3, 4};
    REQUIRE((RotateChunks(input, 1, 1) == std::vector<int>{22, 13, 3, 4}));
  }

  SECTION("Normal case") {
    std::vector<int> input = {22, 13, 3, 4, 16, 6};
    REQUIRE(
        (RotateChunks(input, 3, 1) == std::vector<int>{3, 22, 13, 6, 4, 16}));
  }

  SECTION("Chunk size not divisible by vector size") {
    std::vector<int> input = {22, 13, 3, 4, 16};
    REQUIRE((RotateChunks(input, 2, 1) == std::vector<int>{13, 22, 4, 3, 16}));
  }

  SECTION("Rotation larger than chunk size") {
    std::vector<int> input = {22, 13, 3, 4, 16, 6};
    REQUIRE(
        (RotateChunks(input, 3, 4) == std::vector<int>{3, 22, 13, 6, 4, 16}));
  }

  SECTION("Chunk size of 0") {
    std::vector<int> input = {22, 13, 3, 4};
    REQUIRE((RotateChunks(input, 0, 1) == std::vector<int>{}));
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////
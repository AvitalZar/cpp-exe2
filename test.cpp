#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "squareMat.hpp"
#include "doctest.h"

TEST_CASE("Test Constructor and Sum") {
    theMatrix::SquareMat mat(2); // Create a 2x2 matrix
    CHECK(mat.sum() == 0); // Assuming the sum function calculates the sum of all elements (it should be zero initially)
}

TEST_CASE("Test Assignment Operator") {
    theMatrix::SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    theMatrix::SquareMat mat2(2);
    mat2 = mat1; // Assign mat1 to mat2

    CHECK(mat2[0][0] == 1);
    CHECK(mat2[0][1] == 2);
    CHECK(mat2[1][0] == 3);
    CHECK(mat2[1][1] == 4);
}

TEST_CASE("Test Addition Operator") {
    theMatrix::SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    theMatrix::SquareMat mat2(2);
    mat2[0][0] = 5;
    mat2[0][1] = 6;
    mat2[1][0] = 7;
    mat2[1][1] = 8;

    theMatrix::SquareMat result = mat1 + mat2;

    CHECK(result[0][0] == 6);
    CHECK(result[0][1] == 8);
    CHECK(result[1][0] == 10);
    CHECK(result[1][1] == 12);
}

TEST_CASE("Test Multiplication Operator") {
    theMatrix::SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    theMatrix::SquareMat mat2(2);
    mat2[0][0] = 5;
    mat2[0][1] = 6;
    mat2[1][0] = 7;
    mat2[1][1] = 8;

    theMatrix::SquareMat result = mat1 * mat2;

    CHECK(result[0][0] == 19); // (1*5 + 2*7)
    CHECK(result[0][1] == 22); // (1*6 + 2*8)
    CHECK(result[1][0] == 43); // (3*5 + 4*7)
    CHECK(result[1][1] == 50); // (3*6 + 4*8)
}

TEST_CASE("Test Scalar Multiplication Operator") {
    theMatrix::SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    double scalar = 3;
    theMatrix::SquareMat result = mat * scalar;

    CHECK(result[0][0] == 3);  // (1 * 3)
    CHECK(result[0][1] == 6);  // (2 * 3)
    CHECK(result[1][0] == 9);  // (3 * 3)
    CHECK(result[1][1] == 12); // (4 * 3)
}

TEST_CASE("Test Equality Operators") {
    theMatrix::SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    theMatrix::SquareMat mat2(2);
    mat2[0][0] = 1;
    mat2[0][1] = 2;
    mat2[1][0] = 3;
    mat2[1][1] = 4;

    CHECK(mat1 == mat2);
    CHECK_FALSE(mat1 != mat2);

    mat2[0][0] = 5;
    CHECK_FALSE(mat1 == mat2);
    CHECK(mat1 != mat2);
}

TEST_CASE("Test Increment Operators") {
    theMatrix::SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    theMatrix::SquareMat matCopy = mat++;

    CHECK(mat[0][0] == 2); // Postfix increment
    CHECK(mat[0][1] == 3);
    CHECK(mat[1][0] == 4);
    CHECK(mat[1][1] == 5);

    matCopy = ++mat;

    CHECK(mat[0][0] == 3); // Prefix increment
    CHECK(mat[0][1] == 4);
    CHECK(mat[1][0] == 5);
    CHECK(mat[1][1] == 6);
}

TEST_CASE("Test Invalid Operations (size mismatch)") {
    theMatrix::SquareMat mat1(2);
    theMatrix::SquareMat mat2(3);

    CHECK_THROWS_AS(mat1 + mat2, std::runtime_error);
}

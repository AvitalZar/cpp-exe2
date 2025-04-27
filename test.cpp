#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "squareMat.hpp"
#include "doctest.h"

using namespace theMatrix;

TEST_CASE("Test Constructor") {
    theMatrix::SquareMat mat(2);
    CHECK(mat.sum() == 0);
}

TEST_CASE("Test = Operator") {
    theMatrix::SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    theMatrix::SquareMat mat2(2);
    mat2 = mat1;

    CHECK(mat2[0][0] == 1);
    CHECK(mat2[0][1] == 2);
    CHECK(mat2[1][0] == 3);
    CHECK(mat2[1][1] == 4);
	
	theMatrix::SquareMat mat3 = mat1;

    CHECK(mat3[0][0] == 1);
    CHECK(mat3[0][1] == 2);
    CHECK(mat3[1][0] == 3);
    CHECK(mat3[1][1] == 4);
}

TEST_CASE("Test + Operator") {
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

TEST_CASE("Test * Operator") {
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

TEST_CASE("Test Scalar * Operator") {
    theMatrix::SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    double scalar = 3;
    theMatrix::SquareMat result = mat * scalar;

    CHECK(result[0][0] == 3);
    CHECK(result[0][1] == 6);
    CHECK(result[1][0] == 9);
    CHECK(result[1][1] == 12);
}

TEST_CASE("Test comparison Operators") {
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
	CHECK(mat1<=mat2);
	CHECK(mat2>=mat1);
    CHECK_FALSE(mat1 != mat2);

    mat1[0][0] = 42;
	mat2[0][1] = 43;
	CHECK(mat1==mat2);

	mat2[0][1] = 2;
	CHECK(mat2<mat1);
	CHECK(mat1>mat2);
	CHECK(mat2<=mat1);
	CHECK(mat1>=mat2);
}

TEST_CASE("Test ++,-- Operators") {
    theMatrix::SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    theMatrix::SquareMat matCopy = mat++;

    CHECK(matCopy[0][0]==1);
    CHECK(matCopy[0][1]==2);
    CHECK(matCopy[1][0]==3);
    CHECK(matCopy[1][1]==4);

	CHECK(mat[0][0] == 2);
    CHECK(mat[0][1] == 3);
    CHECK(mat[1][0] == 4);
    CHECK(mat[1][1] == 5);

    matCopy = ++mat;

    CHECK(mat[0][0] == 3);
    CHECK(mat[0][1] == 4);
    CHECK(mat[1][0] == 5);
    CHECK(mat[1][1] == 6);

    CHECK(matCopy[0][0] == 3);
    CHECK(matCopy[0][1] == 4);
    CHECK(matCopy[1][0] == 5);
    CHECK(matCopy[1][1] == 6);
	
	
	
	matCopy = mat--;

    CHECK(matCopy[0][0] == 3);
    CHECK(matCopy[0][1] == 4);
    CHECK(matCopy[1][0] == 5);
    CHECK(matCopy[1][1] == 6);

	CHECK(mat[0][0] == 2);
    CHECK(mat[0][1] == 3);
    CHECK(mat[1][0] == 4);
    CHECK(mat[1][1] == 5);

    matCopy = --mat;

    CHECK(matCopy[0][0]==1);
    CHECK(matCopy[0][1]==2);
    CHECK(matCopy[1][0]==3);
    CHECK(matCopy[1][1]==4);

    CHECK(mat[0][0]==1);
    CHECK(mat[0][1]==2);
    CHECK(mat[1][0]==3);
    CHECK(mat[1][1]==4);
}




TEST_CASE("Testing % operator") {
    SquareMat a(2), b(2);
    a[0][0] = 5; a[0][1] = 7;
    a[1][0] = 2; a[1][1] = 32;

    b[0][0] = 1; b[0][1] = 2;
    b[1][0] = 3; b[1][1] = 2;
    
    SquareMat c = a % b;
    CHECK(c[0][0] == 5);
    CHECK(c[0][1] == 14);
    CHECK(c[1][0] == 6);
    CHECK(c[1][1] == 64);

    
    b = a % 4;
    CHECK(b[0][0] == 1);
    CHECK(b[0][1] == 3);
    CHECK(b[1][0] == 2);
    CHECK(b[1][1] == 0);
}

TEST_CASE("Testing / operator") {
    SquareMat a(2);
    a[0][0] = 4; a[0][1] = 8;
    a[1][0] = 2; a[1][1] = 6;

    SquareMat b = a / 2.0;
    CHECK(b[0][0] == doctest::Approx(2.0));
    CHECK(b[0][1] == doctest::Approx(4.0));
    CHECK(b[1][0] == doctest::Approx(1.0));
    CHECK(b[1][1] == doctest::Approx(3.0));
}

TEST_CASE("Testing ^ operator") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 1; a[1][1] = 0;

    SquareMat b = a ^ 3;

    // a^1 = |1 1|
    //       |1 0|
    // a^2 = |2 1|
    //       |1 1|
    // a^3 = |3 2|
    //       |2 1|
    
    CHECK(b[0][0] == 3);
    CHECK(b[0][1] == 2);
    CHECK(b[1][0] == 2);
    CHECK(b[1][1] == 1);

	SUBCASE("Power 0") {
        SquareMat identity = a ^ 0;
        CHECK(identity[0][0] == doctest::Approx(1.0));
        CHECK(identity[0][1] == doctest::Approx(0.0));
        CHECK(identity[1][0] == doctest::Approx(0.0));
        CHECK(identity[1][1] == doctest::Approx(1.0));
    }

    SUBCASE("Power 1") {
        SquareMat result = a ^ 1;
        CHECK(result[0][0] == 1);
        CHECK(result[0][1] == 1);
        CHECK(result[1][0] == 1);
        CHECK(result[1][1] == 0);
    }

}

TEST_CASE("Testing <op>= operator") {
		SquareMat a(2), b(2);
	
		// Initialize matrices
		a[0][0] = 1; a[0][1] = 2;
		a[1][0] = 3; a[1][1] = 4;
	
		b[0][0] = 5; b[0][1] = 6;
		b[1][0] = 7; b[1][1] = 8;
	
		SUBCASE("operator+=") {
			a += b;
			CHECK(a[0][0] == 6);
			CHECK(a[0][1] == 8);
			CHECK(a[1][0] == 10);
			CHECK(a[1][1] == 12);
		}
	
		SUBCASE("operator-=") {
			b -= a;
			CHECK(b[0][0] == 4);
			CHECK(b[0][1] == 4);
			CHECK(b[1][0] == 4);
			CHECK(b[1][1] == 4);
		}
	
		SUBCASE("operator*= matrix") {
			a *= b;
			CHECK(a[0][0] == 19); // 1*5 + 2*7
			CHECK(a[0][1] == 22); // 1*6 + 2*8
			CHECK(a[1][0] == 43); // 3*5 + 4*7
			CHECK(a[1][1] == 50); // 3*6 + 4*8
		}
	
		SUBCASE("operator/=") {
			a /= 2.0;
			CHECK(a[0][0] == doctest::Approx(0.5));
			CHECK(a[0][1] == doctest::Approx(1.0));
			CHECK(a[1][0] == doctest::Approx(1.5));
			CHECK(a[1][1] == doctest::Approx(2.0));
		}
	
		SUBCASE("operator %= matrix") {
			SquareMat c(2);
			c[0][0] = 2; c[0][1] = 3;
			c[1][0] = 4; c[1][1] = 5;
	
			a %= c;
			CHECK(a[0][0] == 2);
			CHECK(a[0][1] == 6);
			CHECK(a[1][0] == 12);
			CHECK(a[1][1] == 20);
		}
	
		SUBCASE("operator *= double") {
			a *= 2.0;
			CHECK(a[0][0] == 2);
			CHECK(a[0][1] == 4);
			CHECK(a[1][0] == 6);
			CHECK(a[1][1] == 8);
		}
	
		SUBCASE("operator%= int") {
			a[1][1] = 19;
			a %= 3;
			CHECK(a[0][0] == doctest::Approx(1));
			CHECK(a[0][1] == doctest::Approx(2));
			CHECK(a[1][0] == doctest::Approx(0));
			CHECK(a[1][1] == doctest::Approx(1));
		}
	
}

TEST_CASE("Testing SquareMat printing") {
    SquareMat m(3);
	m[0][0] = 0; m[0][1] = 1; m[0][2] = 2;
	m[1][0] = 3; m[1][1] = 4; m[1][2] = 5;
	m[2][0] = 6; m[2][1] = 7; m[2][2] = 8;
    
    std::stringstream ss;
    ss << m;

    std::string expected_output = "0 1 2 \n3 4 5 \n6 7 8 \n";
    
    CHECK(ss.str() == expected_output);
}


TEST_CASE("exceptions") {
    theMatrix::SquareMat mat1(2);
    theMatrix::SquareMat mat2(3);

    CHECK_THROWS_AS(mat1 + mat2, std::runtime_error);
}

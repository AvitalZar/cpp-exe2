#include "squareMat.hpp"
using namespace theMatrix;
using namespace std;

int main(){
	SquareMat sm(3);

	cout<<"new matrix 3X3:"<<endl<<sm<<endl;

	sm[0][0] = 0; sm[0][1] = 1; sm[0][2] = 2;
	sm[1][0] = 3; sm[1][1] = 4; sm[1][2] = 5;
	sm[2][0] = 6; sm[2][1] = 7; sm[2][2] = 8;
}
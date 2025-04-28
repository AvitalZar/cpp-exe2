//tchykzr@gmail.com

#include "squareMat.hpp"
using namespace theMatrix;
using namespace std;

int main(){
	cout<<"start"<<endl;
	SquareMat sm(3);
	
	cout<<"new matrix 3X3:"<<endl<<"A ="<<endl<<sm<<endl;

	sm[0][0] = 0; sm[0][1] = 1; sm[0][2] = 2;
	sm[1][0] = 3; sm[1][1] = 4; sm[1][2] = 5;
	sm[2][0] = 6; sm[2][1] = 7; sm[2][2] = 8;

	cout<<"intialized matrix:"<<endl<<"A ="<<endl<<sm<<endl;


	cout<<"Here are some basic operations on the matrix:"<<endl;
	cout<<"AXA:"<<endl<<(sm^2)<<endl;

	sm++;
	cout<<"A++:"<<endl<<sm<<endl;

	cout << "A*2: " << endl << (sm * 2) << endl;
    cout << "A/2: " << endl << (sm / 2) << endl;
    cout << "3*A: " << endl << (3 * sm) << endl;
	cout<<"-A: "<<endl<<(-sm)<<endl;

	cout<<"|A| = "<<!(--sm)<<endl;

	SquareMat id(36);
	for(int i = 0; i < 36; i++){
		id[i][i] = 1;
	}
	cout<<"|I| = "<<!id<<endl;


	cout<<boolalpha;
	cout<<"searching for other things to show off with..."<<endl;
	cout<<"Is the I_36 equal to A?	"<<(id == sm)<<endl;
	cout<<"Is the I_36 greater than A?	"<<(id > sm)<<endl;
	cout<<"Is AXA less than A?	"<<((sm^2) < (sm))<<endl;

	cout<<endl<<"A transpose: "<<endl<<~sm<<endl;


	cout<<"operations with second matrix:"<<endl;

	SquareMat sm2(3);
    sm2[0][0] = 9; sm2[0][1] = 8; sm2[0][2] = 7;
	sm2[1][0] = 6; sm2[1][1] = 5; sm2[1][2] = 4;
	sm2[2][0] = 3; sm2[2][1] = 2; sm2[2][2] = 1;
    cout << "Second matrix:" << endl << "B =" << endl << sm2 << endl;

	cout << "Here are some basic operations on the matrices:" << endl;
	cout << "A+B: " << endl << (sm + sm2) << endl;

	cout << "A*B: " << endl << (sm * sm2) << endl;
    
	cout << "A%B (product element by element): " << endl << (sm % sm2) << endl;
    cout << "A*2.0: " << endl << (sm * 2.0) << endl;
    cout << "A/2.0: " << endl << (sm / 2.0) << endl;
    cout << "3*A: " << endl << (3 * sm) << endl;


	cout<<"some exception throwing:"<<endl;
	cout << "add matrices of different sizes:" << endl;
    try {
        SquareMat result = sm + id; // 3x3 + 36x36
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
	}
	cout<<"create a negative-size matrix:"<<endl;
	try {
		SquareMat wrong(-1);
	} catch (const invalid_argument& e) {
		cout<<"Cought exception: "<<e.what() << endl;
	}
	
	cout<<"product matrices of different size:"<<endl;
	try {
        SquareMat result = sm * id;
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
	}
}
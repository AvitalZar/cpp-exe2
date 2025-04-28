#include "squareMat.hpp"

using namespace std;
namespace theMatrix{

	SquareMat::SquareMat(int len){
		if(len<1)
			throw invalid_argument("size of the matrix must be at least 1.");
		size = len;
		//cout<<"m";
		mat = new double*[size];
		for(int i = 0; i<size;i++){
			mat[i] = new double[size]();
		}
	}

	SquareMat::SquareMat(const SquareMat &other) : size(other.size){
		cout<<"C";
		mat = new double*[size];
		for(int i = 0; i<size;i++){
			mat[i] = new double[size];
		}


		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				mat[i][j] = other.mat[i][j];
			}
		}
	}

	/*theMatrix::SquareMat::SquareMat(const SquareMat &other)
	{
		*this = other;
	}*/

	SquareMat SquareMat::operator+(const SquareMat& other) const{
		if(other.size!=size){
			throw std::runtime_error("Cannot sum matrices of different size.");
		}
		SquareMat ans(size);

		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				ans[i][j] = mat[i][j] + other[i][j];
			}
		}
		return ans;
	}

	SquareMat theMatrix::SquareMat::operator-(const SquareMat& other) const
	{
		if(other.size!=size){
			throw std::runtime_error("Cannot sub matrices of different size.");
		}
		SquareMat ans(size);

		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				ans[i][j] = mat[i][j] - other[i][j];
			}
		}
		return ans;
	}

	SquareMat theMatrix::SquareMat::operator-()
	{
		SquareMat ans(size);
		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				ans[i][j] = -mat[i][j];
			}
		}
		
		return ans;
	}

	SquareMat theMatrix::SquareMat::operator*(const SquareMat& other) const
	{	
		if(other.size!=size){
			throw std::runtime_error("Cannot product matrices of different size.");
		}
		SquareMat ans(size);
		//go over the new matrix:
		
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				ans[i][j] = 0;
				//inner-product the current row of "this" with the current column of "other"
				for(int k = 0; k < size;k++){
					ans[i][j] += (*this)[i][k]*other[k][j];
				}
			}
		}

		return ans;
	}

	SquareMat theMatrix::SquareMat::operator*(double p) const
	{
		SquareMat ans(size);
		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				ans[i][j] = p*mat[i][j];
			}
		}

		return ans;
	}

	SquareMat theMatrix::SquareMat::operator%(const SquareMat &other) const
	{
		if(other.size!=size){
			throw std::runtime_error("Cannot % matrices of different size.");
		}
		SquareMat ans(size);

		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				ans[i][j] = mat[i][j] * other[i][j];
			}
		}
		return ans;
	}

	SquareMat theMatrix::SquareMat::operator%(int p) const
	{
		SquareMat ans(size);
		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				ans[i][j] = fmod(mat[i][j],p);
			}
		}

		return ans;
	}

	SquareMat theMatrix::SquareMat::operator/(double num) const
	{
		SquareMat ans(size);
		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				ans[i][j] = mat[i][j]/num;
			}
		}

		return ans;
	}

	SquareMat theMatrix::SquareMat::operator^(int n) const
	{
		SquareMat ans(size);
		for(int i = 0; i < size; i++){
			ans[i][i] = 1;
		}
		while(n>0){
			ans *= *this;
			n--;
		}
		return ans;
	}

	SquareMat& theMatrix::SquareMat::operator++()
	{
		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				mat[i][j]++;
			}
		}

		return *this;
	}

	SquareMat theMatrix::SquareMat::operator++(int)
	{	
		SquareMat ans = *this;
		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				mat[i][j]++;
			}
		}

		return ans;
	}

	SquareMat& theMatrix::SquareMat::operator--()
	{
		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				mat[i][j]--;
			}
		}

		return *this;
	}

	SquareMat theMatrix::SquareMat::operator--(int)
	{	
		SquareMat ans = *this;
		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				mat[i][j]--;
			}
		}

		return ans;
	}

	SquareMat theMatrix::SquareMat::operator~()
	{
		SquareMat ans(size);
		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				ans[i][j] = mat[j][i];
			}
		}

		return ans;
	}

	bool operator==(const SquareMat& cur, const SquareMat& other){
		return cur.sum() == other.sum();
	}

	bool operator!=(const SquareMat& cur, const SquareMat& other)
	{
		return cur.sum() != other.sum();
	}

	bool operator<(const SquareMat& cur, const SquareMat& other)
	{
		return cur.sum() < other.sum();
	}

	bool operator>(const SquareMat& cur, const SquareMat& other)
	{
		return cur.sum() > other.sum();
	}

	bool operator<=(const SquareMat& cur, const SquareMat& other)
	{
		return cur.sum() <= other.sum();
	}

	bool operator>=(const SquareMat& cur, const SquareMat& other)
	{
		return cur.sum() >= other.sum();
	}

	ostream &operator<<(ostream &output, const SquareMat& t)
	{
		for(int i = 0; i<t.get_size(); i++){
			for(int j = 0;j<t.get_size();j++){
				output << t[i][j] << " ";
			}
			output << endl;
		}
		return output;
	}

	void addp(double *res, double* a, double* b, int p, int len){
		for(int i = 0; i < len; i++){
			res[i] = a[i] + p*b[i];
		}
	}
		double theMatrix::SquareMat::operator!() const {
			SquareMat temp = *this;
			//cout<<*this<<endl;
			int sign = 1;
			
			//go over all the major diagonal.
			for(int i = 0; i < size; i++){
				//we need the i,i place not to be 0.
				if(temp.mat[i][i] == 0) {
					int row;
					for(row = i; row < size; row++) {
						if(temp.mat[row][i] != 0) {
							break;
						}
					}
					if(row == size) //there's a column with no leading-coefficient.
						return 0; 
					double *temporary = temp.mat[i];
					temp.mat[i] = temp.mat[row];
					temp.mat[row] = temporary;
					sign *= (-1);
					//now we have leading-coefficient in i,i.
				}

				for(int r = i + 1; r < size; r++){
					double p = temp[r][i]/temp[i][i];
					//cout<<"p = "<<p<<endl;
					//cout<<"1.r,i = "<<mat[r][i]<<endl;
					addp(temp[r], temp[r], temp[i], -p, size);
					//cout<<"2.r,i = "<<mat[r][i]<<endl;;
				}
			}
			double ans = 1;
			for(int i = 0; i < size; i++){
				ans *= temp[i][i];
			}
			return ans;
		}

	//הפונקציה הישנה שלי לחישוב דטרמיננטה עם מינורים;
	//מסתבר שהיא לוקחת כמו לבנות יקום.
	/*double theMatrix::SquareMat::operator!() const
	{
		if(size==1){
			return mat[0][0];
		}
		if(size==2){
			return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
		}
		
		int ans = 0;
		SquareMat minor(size-1);
		int rminor,cminor;
		for(int k = 0; k < size; k++){
			
			rminor = 0;
			for(int i = 1; i < size; i++,rminor++){
				cminor = 0;
				for(int j = 0; j < size; j++){
					if(j != k){
						minor[rminor][cminor] = mat[i][j];
						cminor++;
					}
				}
			}

			ans += (k % 2 == 0 ? 1 : -1) * mat[0][k] * !minor;
		}
		return ans;
	}*/

	SquareMat& theMatrix::SquareMat::operator*=(const SquareMat &other)
	{	
		*this = (*this)*other;
		return *this;
	}

	SquareMat& theMatrix::SquareMat::operator+=(const SquareMat &other)
	{
		*this = (*this) + other;
		return *this;
	}


	SquareMat& theMatrix::SquareMat::operator-=(const SquareMat &other)
	{
		*this = (*this) - other;
		return *this;
	}

	SquareMat& theMatrix::SquareMat::operator/=(double x)
	{
		*this = (*this) / x;
		return *this;
	}
	SquareMat& theMatrix::SquareMat::operator%=(double x)
	{
		*this = (*this) % x;
		return *this;
	}

	SquareMat& theMatrix::SquareMat::operator%=(const SquareMat &other)
	{
		*this = (*this) % other;
		return *this;
	}

	SquareMat& theMatrix::SquareMat::operator*=(double x)
	{
		*this = (*this) * x;
		return *this;
	}

	SquareMat operator*(double p, SquareMat& m){
		return m*p;
	}


	double theMatrix::SquareMat::sum() const
	{
		double ans = 0;
		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				ans += mat[i][j];
			}
		}
		return ans;
	}

	int SquareMat::get_size() const
	{
		return size;
	}

	const double* theMatrix::SquareMat::operator[](int i) const
	{
		//cout<<"access the "<<i<<"th row."<<endl;
		return mat[i];
	}
	double* theMatrix::SquareMat::operator[](int i)
	{
		return mat[i];
	}

	SquareMat& theMatrix::SquareMat::operator=(const SquareMat &other)
	{	
		if(other.get_size()!=size){
			for(int i = 0;i<size;i++){
				delete[] mat[i];
			}
			delete[] mat;
			size = other.size;
			mat = new double*[size];
			for(int i = 0; i<size;i++){
				mat[i] = new double[size];
			}
		}


		for(int i = 0; i<size; i++){
			for(int j = 0;j<size;j++){
				mat[i][j] = other.mat[i][j];
			}
		}

		return (*this);
	}

	

}
theMatrix::SquareMat::~SquareMat()
{
	if(mat){
	for(int i = 0;i<size;i++){
		delete[] mat[i];
	}
	delete[] mat;
	mat = nullptr;
	size = 0;
}
}


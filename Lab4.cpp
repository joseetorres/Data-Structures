#include <iostream>
#include <cstdlib>
 
using namespace std;
 
template <class T>
 
class Matrix
	{
		private:
				int R; 
				int C; 
				T *m;  
 
		public:
				T &operator()(int r, int c)
					{
						return m[r+c*R];
					}
 
				Matrix(int R0, int C0)
					{
						R=R0; C=C0; m=new T[R*C];
						for (int i = 0; i < R * C; i++)
							{
								m[i] = T();
							}
					}
 
				Matrix(const Matrix & cSource)    
					{
						R = cSource.R;
						C = cSource.C;
						m = new T [R*C];
						for(int i = 0; i < R*C; i++)
							{
								m[i] = cSource.m[i];
							}
					}
 
				Matrix& operator = (const Matrix  &);
				template<class M>
				friend  ostream& operator << (ostream& out, const Matrix<M>  &);
				template<class I>
				friend  istream& operator >> (istream& in, const Matrix<I>  &);
				~Matrix();
	};
 
template <class T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T> & cSource)
	{
		R = cSource.R;
		C = cSource.C;
		delete[] m;
		m = new T [R*C];
		for(int i = 0; i < R*C; i++)
			{
				m[i] = cSource.m[i];
			}
		return *this;        
	}
 
template <class M>
ostream& operator << (ostream& out, const Matrix<M> & cSource)
	{
		out << endl;
		for(int i = 0; i < cSource.R; i++)
			{
				for(int j = 0; j < cSource.C; j++)
					{
						out << cSource.m[i*cSource.C +j] << " ";
					}
				out << endl;
			}
		return out;       
	}
 
template <class I>
istream& operator >> (istream& in, const Matrix<I> & cSource)
	{ 
		for(int i = 0; i < cSource.R; i++)
			{
				for(int j = 0; j < cSource.C; j++)
					{
						in >> cSource.m[i*cSource.C +j] << " ";
					 }
			}
		return in;        
	}
 
template <class T>
Matrix<T>::~Matrix ()
	{
		delete[] m;
	}
 
int main()
{
    Matrix<int> a(3,3);
    a(1,1) = 1;
 
    Matrix<int> b(3,3);
    b = a;
 
    cout << a(1,1);
    cout << b;
	system("Pause");
};
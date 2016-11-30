#include <iostream>
#include <cstdlib>
using namespace std; 

void bubbleSort (int v[ ], unsigned int n)
{
		for (unsigned int i = n - 1; i > 0; i--) {
		for (unsigned int j = 0; j < i; j++) {

				
			if (v[j] > v[j+1]) {
				
				double temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				}
			}
		}
}


int main () {
	int v[20000];
	int i;
	for (i = 0; i < 20000; i++)
		v[i] = rand()%100000;
	bubbleSort(v, 20000);
	for (i = 0; i < 20000; i++)
		cout << v[i] << ' ';
	cout << "\n";
}


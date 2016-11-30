#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

int pivot (vector<int> & v, int start, int stop, int position)
{
        swap(v[start], v[position]);
        
        int low = start + 1;
        int high = stop;
        while(low < high)
        {
                if(v[low] < v[start])
                {
                        low++;
                }
                else if(v[--high] < v[start])
                {
                        swap(v[low], v[high]);
                }
        }
        
        swap(v[start], v[--low]);
        return low;
}

void quickSort(vector<int> & v, int low, int high)
{
        if(low>=high)
        {
                return;
        }
        
        int pivotIndex = (low + high) / 2;
        
        pivotIndex = pivot(v, low, high, pivotIndex);
        
        if(low < pivotIndex)
        {
                quickSort(v, low, pivotIndex);
        }
        
        if(pivotIndex < high)
        {
                quickSort(v, pivotIndex + 1, high);
        }
}

void print(vector<int> & v) 
{
        for(int i = 0; i < v.size(); i++)
        {
                cout << v[i] << " ";
        }
}

int main()
{
double c;
c = clock(); 
        int n = 1000000;
        int low = 200000;
        int high = 850000;
        
        vector<int> increasing(n);
        for(int i = 0; i < n; i++)
        {
                increasing[i]=i;
        }
        
        vector<int> decreasing(n);
        int j = n-1;
        for(int i = 0; i < n; i++)
        {
                decreasing[i]=j;
                j--;
        }
        
        vector<int> random(n);
        for(int i = 0; i < n; i++)
        {
                random[i]=rand() % 100;
        }
        
     
        
        quickSort(decreasing, low, high);
        
    
        
        c = clock() - c;
        
        cout << "N: " << n << endl;
        cout << "Low: " << low << endl;
        cout << "High: " << high << endl;
        cout << "Data-set: decreasing vector " << endl;
        cout << "Ticks: " << clock() << endl; // output difference - ticks 
        cout << "Seconds: " << c/CLOCKS_PER_SEC << endl; // output difference - seconds

return 0;
}



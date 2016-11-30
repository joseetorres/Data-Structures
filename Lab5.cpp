#include <iostream>
#include <stack>

using namespace std;

stack<int> a, b, c;

void moveab()
{
        if(a.empty())
        {
                a.push(b.top());
                b.pop();
                cout << "move b to a" << endl;
        }
        else if(b.empty())
        {
                b.push(a.top());
                a.pop();
                cout << "move a to b" << endl;
        }
        else if(a.top() > b.top())
        {
                a.push(b.top());
                b.pop();
                cout << "move b to a" << endl;
        }
        else if(b.top() > a.top())
        {
                b.push(a.top());
                a.pop();
                cout << "move a to b" << endl;
        }
}

void moveac()
{
        if(a.empty())
        {
                a.push(c.top());
                c.pop();
                cout << "move c to a" << endl;
        }
        else if(c.empty())
        {
                c.push(a.top());
                a.pop();
                cout << "move a to c" << endl;
        }
        else if(a.top() > c.top())
        {
                a.push(c.top());
                c.pop();
                cout << "move c to a" << endl;
        }
        else if(c.top() > a.top())
        {
                c.push(a.top());
                a.pop();
                cout << "move a to c" << endl;
        }
}

void movebc()
{
        if(c.empty())
        {
                c.push(b.top());
                b.pop();
                cout << "move b to c" << endl;
        }
        else if(b.empty())
        {
                b.push(c.top());
                c.pop();
                cout << "move c to b" << endl;
        }
        else if(c.top() > b.top())
        {
                c.push(b.top());
                b.pop();
                cout << "move b to c" << endl;
        }
        else if(b.top() > c.top())
        {
                b.push(c.top());
                c.pop();
                cout << "move c to b" << endl;
        }
}

int pow(int x, int exp) // used to compute estimated work
{
        int answer = x;
        for(int i = 1; i < exp; i++)
        {
                answer = answer * x;
        }
        
        return answer;
}

int main()
{
        int n;
        int work = 0;
        cout << "Choose Number of Disks: ";
        cin >> n;
        for(int i = n; i > 0; i--)
        {
                a.push(i);
        }
        bool even;
        if(n % 2 == 0)
                even = true;
        else
                even = false;

        while(even)
        {
                moveab();
                work++;
                if(c.size() == n)
                {
                        break;
                }
                moveac();
                work++;
                if(c.size() == n)
                {
                        break;
                }
                movebc();
                work++;
                if(c.size() == n)
                {
                        break;
                }
        }

        while(! even)
        {
                moveac();
                work++;
                if(c.size() == n)
                {
                        break;
                }
                moveab();
                work++;
                if(c.size() == n)
                {
                        break;
                }
                movebc();
                work++;
                if(c.size() == n)
                {
                        break;
                }
        }
        
        int estimate = pow(2, n) - 1; // because the work done should be (2^N) - 1
        
        cout << "Number of disks is: " << n <<  "." << endl;
        cout << "Work should be (2^N) - 1, which should be: " << estimate << "." << endl;
        cout << "Amount of work done is: " << work  << "." << endl;
   
return 0;
}



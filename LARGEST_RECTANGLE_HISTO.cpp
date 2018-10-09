#include <iostream>
#include <set>
#include <stack>
using namespace std;

int getMaxArea(int hist[], int n)
{
 
    stack < int >s;
    
    int M=0;
    int top;
    int area;
    
    
    int i=0;
    
while(i<n)    {
        if(s.empty() || hist[s.top()]<=hist[i])
            s.push(i++);
        else
        {
            top = s.top();
            s.pop();
            
            area = hist[top]*(s.empty()?i:i-s.top()-1);
            if(area>M)M=area;
        }
    }
    
    while(!s.empty())
    {
        top = s.top();
        s.pop();
        
        area = hist[top]*(s.empty()?i:i-s.top()-1);
        if(area>M)M=area;
    }
    
    
    
    return M;



int main()
{  int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}
    


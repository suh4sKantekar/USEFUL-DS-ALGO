#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <vector>
using namespace std;

//https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg link for
// add edges in graph , undirected edges do add to u and v both.


//set dist int_max;
//set dist  0 for source
/*
loop v-1 times for e edges
check if dist not INT_MAX and check weight edge + u weight
update

again run loop once on e edges check if minimising again
if does negative weight is_copy_constructible<<#class _Tp#>>



*/



int main()
{
    
    std::ios_base::sync_with_stdio(false);
 
    vector <pair<int,pair <int,int> > > vec;
    vec.push_back({ -8,{0,7 } });
    vec.push_back({ 4,{0,1 } });
    vec.push_back({1 ,{7,6 } });
    vec.push_back({ 7,{7,8 } });
    vec.push_back({ 8,{1,2 } });
    vec.push_back({ 11,{1,7 } });
    vec.push_back({ 7,{2,3 } });
    vec.push_back({ 4,{2,5 } });
    vec.push_back({ 10,{5,4 } });
    vec.push_back({ 2,{6,5 } });
    vec.push_back({ 6,{8,6 } });
    vec.push_back({ 2,{2,8 } });
    vec.push_back({ 9,{3,4 } });
    vec.push_back({ 14,{3,5 } });
 
    vector < vector < pair <int,int> > > adj;
    vector < pair <int,int> > a;
    for(int i=0;i<9;i++)adj.push_back(a);
  
    for(int i=0;i<vec.size();i++)
    {
        adj[ vec[i].second.first] .push_back( { vec[i].second.second,vec[i].first }  );
        adj[ vec[i].second.second] .push_back( { vec[i].second.first,vec[i].first }  );
    }
    
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout <<adj[i][j].first<<" :"<<adj[i][j].second<<" ";
        }
        cout <<endl;
    }
   
    priority_queue < pair < int,int >,vector <pair < int,int > > ,greater <pair < int,int >   > > pq;
    int n=9;
    vector < int > val(n,INT_MAX);
    
    
    int src =0;
    
    val[src]=0;
    
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<vec.size();j++)
        {
            int u = vec[j].second.first;
            int v  =vec[j].second.second;
            
            if(val[u]!=INT_MAX && val[v] > val[u] + vec[j].first )
            {
                val[v] =  val[u] + vec[j].first;
            }
        }
    }
    
    for(int j=0;j<vec.size();j++)
    {
        int u = vec[j].second.first;
        int v  =vec[j].second.second;
        
        if(val[u]!=INT_MAX && val[v] > val[u] + vec[j].first )
        {
            cout <<"graph contains negative cycle";
            return 0;
        }
    }
    
    
    
    
    
    
    
 

    for(int i=0;i<9;i++)
    {
        cout <<i<<" : "<<val[i]<<endl;
    }
    
  

    
}




#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <vector>
using namespace std;

//https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg link for
// add edges in graph , undirected edges do add to u and v both.

//set parent -1;
//set dist int_max;
// set included as false;

//add 0 with 0 distance as source to min prio queue with pair as <vertex , distance>
//pop
//traverse adjacent check for unvisietd vertex and dist greater than edge sstance
//update and add to que;
//change parent





int main()
{
    
    std::ios_base::sync_with_stdio(false);
 
    vector <pair<int,pair <int,int> > > vec;
    vec.push_back({ 8,{0,7 } });
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
    
    
    vector < int > P(n,-1);
    vector < bool > IN(n,false);
 
    pq.push({0,0});
    val[0]=0;
    cout <<"que"<<endl;
    while(!pq.empty())
    {
        pair < int,int > p =pq.top();
        pq.pop();
        
        IN[p.first] = true;
        
        cout <<p.first<<"  "<<p.second<<endl;
        
        for(int i=0;i<adj[p.first].size();i++)
        {
         
            if( IN[adj[p.first][i].first]==false && val[adj[p.first][i].first] > adj[p.first][i].second  )
            {
                val[ adj[p.first][i].first] = adj[p.first][i].second;
             
                
                pq.push({adj[p.first][i].first,adj[p.first][i].second});
                P[adj[p.first][i].first] = p.first;
            
              }
            
        }
    }
    
    int sum=0;
    for(int i=0;i<9;i++)
    {   sum+=val[i];
        cout <<i<<" : "<<P[i]<<endl;
    }
    
    cout <<" ::"<<sum;
 
}




prims and kruskal work only for weighted UNDIRECTED graphs 

int Solution::solve(int A, vector<vector<int> > &B) {
    vector < vector <pair <int,int> > > vec;
    vector <pair <int,int> > temp;
    int n=A;
    for(int i=0;i<=A;i++)
    {
        vec.push_back(temp);
    }
    
    for(int i=0;i<B.size();i++)
    {
        vec[B[i][0]].push_back({B[i][1],B[i][2]});
        vec[B[i][1]].push_back({B[i][0],B[i][2]});

    }
    
    int V[n+1];
    int P[n+1];
    int d[n+1];
    for(int i=1;i<=A;i++){V[i]=P[i]=0;d[i]=INT_MAX;}
    d[1]=0;
    priority_queue< pair < int,int > ,vector <pair < int,int > >,greater< pair < int,int > > >pq;
    pq.push({d[1],1});
    
    
    

    
while(!pq.empty())
{
    int u = pq.top().second;
    pq.pop();
    V[u]=1;
    for(int i=0;i<vec[u].size();i++)
    {   pair <int,int>p = vec[u][i]; 
       
        if(V[p.first]==0 && d[p.first]>p.second)
        {   
            d[p.first]=p.second;
            pq.push({d[p.first],p.first});
            P[p.first]=u;
        }
    }
}
    
    
    int sum=0;
    
    for(int i=1;i<=A;i++)
    {int j=2;
 
    sum+=d[i];
    }
    return sum;
    

    
    
}


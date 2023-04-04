 #include<bits/stdc++.h>
 using namespace std;

 int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Code here
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        vector<int > v;
        v.push_back(arr[start_x][start_y]);
        queue<pair<int,int> > q;
        q.push({start_x,start_y});
        //q.push(NULL);
        int dx[]={-1,1,2,2,1,-1,-2,-2};
        int dy[]={-2,-2,-1,1,2,2,1,-1};
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            q.pop();
            int x=node.first;
            int y=node.second;
            if(vis[x][y] == 0)
            {
                vis[x][y]=1;
                //cout<<node.first<<"  "<<node.second;
                //cout<<endl;
                
                 int sum=0;
                for(int i=0;i<8;i++)
                {
                    int point1=x+dx[i];
                    int point2=y+dy[i];
                    
                        //cout<<point1;
                        if(point1 >=0 && point1<n && point2>=0 && point2<m)
                        {
                            sum+=arr[point1][point2]; 
                            q.push({point1,point2});
                        } 
                }
                v.push_back(sum);
            }
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<"    ";
        }
    }
    int main()
    {
        vector<vector<int> > arr={
            {7,6,8},
            {9,1,4},
            {6,2,8}
        };
        knightInGeekland(2,1,arr);
        return 0;
    }
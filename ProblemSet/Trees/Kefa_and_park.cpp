#include <iostream>
#include <vector>

using namespace std;


int dfs(vector<vector<int>>& adj,vector<int>& cats,int root, int parent, int m,int num_cats,int num_of_res){

    if(cats[root] == 0){
            num_cats = 0;
    }
    else{
            num_cats++;
    }
    if(num_cats > m){
            return num_of_res;
    }

    if(adj[root].size() == 0){
        if(cats[root] == 0){
            return 1;
        }else{
            return 0;
        }
    }

    if(adj[root].size() == 1 && root != 1){
        return num_of_res+1;
    }else{
        
        for(int i = 0; i<adj[root].size(); i++){
            int curr_node = adj[root][i];
            if(curr_node == parent){
                continue;
            }else{
                num_of_res = dfs(adj,cats,curr_node,root,m,num_cats,num_of_res);
            }
        }
        return num_of_res;
    }
}
   
void solver(vector<vector<int>>& adj, vector<int> &v,int max_allowed_con_cats){

    int num_of_r = 0;

    cout << dfs(adj,v,1,0,max_allowed_con_cats,0,0);

}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> v(n+1);

    for(int i = 1; i<n+1; i++){
        cin >> v[i];
    }

    vector<vector<int>> adj(n+1);

    for(int i = 1; i<n; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    solver(adj,v,m);


}
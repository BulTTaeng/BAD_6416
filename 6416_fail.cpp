#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> V[10001];
vector<bool> ans;

bool have_edge[10001];
bool is_node[10001];
bool visit[10001];

bool poss = true;

void dfs(int start);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int u , v , maxi = 0 , mini = 987654321;
    int root;

    memset(have_edge, false ,sizeof(have_edge));
    memset(is_node , false , sizeof(is_node));

    while(true){
        cin >> u >> v;

        if( u < 0 && v < 0){
            break;
        }


        if(u == 0 && v == 0){
            memset(visit ,false ,sizeof(visit));
            root = -1;
            poss = true;
            bool have = false;

            for(int i = mini; i<=maxi ; i++){
                if(is_node[i]){
                    have = true;
                    if(!have_edge[i]){
                        if(root == -1){
                            root = i;
                            break;
                        }
                        else{
                            root = -1;
                            break;
                        }
                    }
                }
            }

            if(!have){
                ans.push_back(true);
            }

            else if(root == -1){
                ans.push_back(false);
            }
            else{
                dfs(root);
                ans.push_back(poss);
            }

            //V->clear();

            for(int i =mini; i<=maxi; i++){
                V[i].clear();
            }

            //cout << root << " ";
            maxi = 0 ; 
            mini = 987654321;
            memset(have_edge, false ,sizeof(have_edge));
            memset(is_node , false , sizeof(is_node));

        }
        else{
            is_node[u] = true;
            is_node[v] = true;
            have_edge[v] = true;

            V[u].push_back(v);
            maxi = max(maxi , u);
            maxi = max(maxi , v);

            mini = min(mini , u);
            mini = min(mini , v); 
        }
    }

    for(int i =0; i<ans.size(); i++){
        if(ans[i]){
            cout << "Case "  << i+1 <<  " is a tree."  << "\n";
        }
        else{
            cout << "Case "  << i+1 <<  " is not a tree." << "\n";
        }
    }

    return 0;


}

void dfs(int start){
    visit[start] = true;

    for(int i =0; i<V[start].size() ; i++){
        if(!visit[V[start][i]]){
            dfs(V[start][i]);
        }
        else{
            
            //cout << start <<" " << V[start][i] << "\n";
            poss = false;
            return;
        }
    }
}
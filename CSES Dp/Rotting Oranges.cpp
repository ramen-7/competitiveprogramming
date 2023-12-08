//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int oranges = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    oranges++;
                }
            }
        }
        
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        int time = -1;
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto& cur = q.front();
                q.pop();
                int cur_i = cur.first;
                int cur_j = cur.second;
                if(grid[cur_i][cur_j] == 1) {
                    oranges--;
                }
                grid[cur_i][cur_j] = -1;
                for (int j = 0; j < 4; j++) {
                    int new_i = cur_i + d[j].first;
                    int new_j = cur_j + d[j].second;
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 1) {
                        q.push({new_i, new_j});
                    }
                }
            }
            time++;
            if (oranges == 0) {
                break;
            }
            
        }
        
        return oranges == 0? time: -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends-
// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dis(r, vector<int>(c, INT_MAX));
        queue<vector<int>> que;//{i, j}
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) {
                    dis[i][j] = 0;
                    que.push({i, j});
                }
            }
        if (que.size() == 0 || que.size() == r * c)
            return -1;
        int ds[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (que.size()) {
            vector<int> cur = que.front();
            que.pop();
            for (auto & d : ds) {
                int x = cur[0] + d[0];
                int y = cur[1] + d[1];
                int dd = dis[cur[0]][cur[1]] + 1;
                if (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == 0 && dis[x][y] > dd) {
                    dis[x][y] = dd;
                    que.push({x, y});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 0)
                    ans = max(ans, dis[i][j]);
        return ans;
    }
};


int main(void)
{
    Solution s1;

    vector<vector<int>> grid = {
        {1,0,0,0,0,1,0,0,0,1},
        {1,1,0,1,1,1,0,1,1,0},
        {0,1,1,0,1,0,0,1,0,0},
        {1,0,1,0,1,0,0,0,0,0},
        {0,1,0,0,0,1,1,0,1,1},
        {0,0,1,0,0,1,0,1,0,1},
        {0,0,0,1,1,1,1,0,0,1},
        {0,1,0,0,1,0,0,1,0,0},
        {0,0,0,0,0,1,1,1,0,0},
        {1,1,0,1,1,1,1,1,0,0}};


    int res = s1.maxDistance(grid);


    cout<<res<<endl;

    return 0;
}
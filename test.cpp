#include <bits/stdc++.h>

using namespace std;

/* Grid Point */
class Point {
private:
public:
    int x;
    int y;
    int k;
    Point(int x, int y, int k) : x(x), y(y), k(k) {}
};

class Solution {
private:
    /* Pacific Atlantic Water Flow */
    vector<vector<int>> ans;
    void reachOcean(vector<vector<int>>& heights, int r, int c,
                    vector<vector<bool>>& reachPacific,
                    vector<vector<bool>>& reachAtlantic,
                    vector<int> offset) {
        // Base case:
            // Reach out of the island
            // If the cell is not false
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size()) return;
        
        for (int i = 0; i < 4; i++) {
            int ver = r + offset[i];
            int hor = c + offset[i+1];
            
            if (ver >= 0 && ver < heights.size() &&
                hor >= 0 && hor < heights[0].size() &&
                heights[ver][hor] <= heights[r][c]) 
            {
                reachOcean(heights, ver, hor, reachPacific, reachAtlantic, offset);
                if (reachPacific[ver][hor]) reachPacific[r][c] = true;
                if (reachAtlantic[ver][hor]) reachAtlantic[r][c] = true;
            }
        }
        
        if (reachPacific[r][c] && reachAtlantic[r][c]) {
            vector<int> tmp {r, c};
            ans.push_back(tmp);
        }
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, -1));
        // Use BFS
        queue<Point*> q;
        Point* firstPt = new Point(0, 0, k);
        q.push(firstPt);
        bool findEnd = false;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Point* curPt = q.front();
                q.pop();
                if (curPt->x == rows-1 && curPt->y == cols-1) {
                    return ans;
                    // findEnd = true;
                    // break;
                }
                if (grid[curPt->x][curPt->y] == 1) {
                    if (curPt->k > 0) curPt->k--;
                    else continue; 
                }
                if (visited[curPt->x][curPt->y] != -1 && visited[curPt->x][curPt->y] >= curPt->k) continue;
                visited[curPt->x][curPt->y] = ans;
                // Down adjacent point
                if (curPt->x < rows-1) {
                    q.push(new Point(curPt->x+1, curPt->y, curPt->k));
                }
                // Right adjacent point
                if (curPt->y < cols-1) {
                    q.push(new Point(curPt->x, curPt->y+1, curPt->k));
                }
                // Left adjacent point
                if (curPt->y > 1) {
                    q.push(new Point(curPt->x, curPt->y-1, curPt->k));
                }
                // Above adjacent point
                if (curPt->x > 1) {
                    q.push(new Point(curPt->x-1, curPt->y, curPt->k));
                }
            }
            // if (findEnd) break;
            ans++;
        }
        return ans;
    }

    /* Pacific Atlantic Water Flow */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<int> offset {0, -1, 0, 1, 0};
        // Must reach both pacific and atlantic ocean
        // Init two grids showing if the cell can flow to each ocean
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> reachPacific (n, vector<bool> (m, false));
        vector<vector<bool>> reachAtlantic (n, vector<bool> (m, false));
        for (int i = 0; i < n; i++) {
            reachPacific[i][0] = true;
            reachAtlantic[i][m-1] = true;
        }
        for (int i = 0; i < m; i++) {
            reachPacific[0][i] = true;
            reachAtlantic[n-1][i] = true;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                reachOcean(heights, i, j, reachPacific, reachAtlantic, offset);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << reachPacific[i][j] << " "; 
            }
            cout<<endl;
        } cout<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << reachAtlantic[i][j] << " "; 
            }
            cout<<endl;
        }
        // Call to dfs
        return ans;
    }

    /* Bus Routes */
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 1;
        int buses = 1;
        // Construct a graph
        unordered_map<int, vector<int>> graph;
        unordered_set<int> exchangedPt;
        for (auto r : routes) {
            for (int p = 0; p < r.size(); p++) {
                if (graph.find(r[p]) != graph.end()) {
                    exchangedPt.insert(r[p]);
                }
                if (p > 0 &&
                    !binary_search(graph[r[p]].begin(), graph[r[p]].end(), r[p-1])) {
                    graph[r[p]].push_back(r[p-1]);
                }
                
                if (p < r.size()-1 &&
                    !binary_search(graph[r[p]].begin(), graph[r[p]].end(), r[p+1])) {
                    graph[r[p]].push_back(r[p+1]);
                }
            }
        }
        // for (auto ver : graph) {
        //     cout << ver.first << ": ";
        //     for (int n : ver.second) cout << n <<" ";
        //     cout << endl;
        // }
        // for (int n : exchangedPt) cout<<n<<" ";
        // Start from the source, perform bfs
        // If a node is in exchangeRoute, increment buses
        // Found the node, return buses
        queue<int> q;
        unordered_set<int> visited;
        q.push(source);
        visited.insert(source);
        
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curPt = q.front();
                q.pop();
                if (exchangedPt.find(curPt) != exchangedPt.end()) buses++;
                
                for (int nei : graph[curPt]) {
                    if (visited.find(nei) == visited.end()) {
                        if (nei == target) return buses;
                        q.push(nei);
                        visited.insert(nei);
                    }
                }
            }
        }
        
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    /* Shortest Path */
    vector<vector<int>> input {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    // input = {
    //     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    //     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //     {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    //     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    //     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    // };
    /* Pacific Atlantic Water Flow */
    // input = {
    //     {1,2,2,3,5},
    //     {3,2,3,4,4},
    //     {2,4,5,3,1},
    //     {6,7,1,4,5},
    //     {5,1,1,2,4}
    // };
    /* Bus Routes */
    input = {
        {1,2,7},
        {3,6,7},
        {3,12,9},
        {7,12},
        {9,10},
        {12,9,10}
    };
    Solution* solution;
    // int result = solution->shortestPath(input, 1);
    // cout << result << endl;
    // vector<vector<int>> result = solution->pacificAtlantic(input);
    // for (auto arr : result) {
    //     for (int n : arr) {
    //         cout << n<<",";
    //     }
    //     cout << " ";
    // } 
    int result = solution->numBusesToDestination(input, 1, 10);
    cout << result << endl;
    cout << endl;
    return 0;
}

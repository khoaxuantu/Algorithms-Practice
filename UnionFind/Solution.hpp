#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

class UnionFind
{
private:
    vector<int> id;
    vector<int> heights;
    int count = 0;
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            id.push_back(i);
            heights.push_back(1);
        }
    }
    void setCount(int n) {
        count = n;
    }
    int getCount() {
        return count;
    }
    int find(int i) {
        int x = i;
        while (id[i] != i) {
            // id[i] = id[id[i]];
            i = id[i];
        }
        id[x] = i;
        return i;
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    void Union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (heights[rootP] < heights[rootQ]) {
            id[rootP] = rootQ;
            heights[rootQ] += heights[rootP];
        }
        else {
            id[rootQ] = rootP;
            heights[rootP] += heights[rootQ];
        }
        count--;
    }
};


/**
 * @brief Redundant Connection
 * 
 * @param edges The graph which is represented as an array of length n where
 * edges[i] = [a,b] indicates that there is an edge between node a and node b 
 * 
 * @return :vector<int>: An edge than can be removed so that the resulting 
 * graph is a tree of n nodes
 */
class RedundantConnection
{
private:
    vector<vector<int>> edges;
public:
    RedundantConnection(vector<vector<int>>& input) : edges(input) {}
    vector<int> solve() {
        vector<int> ans;
        UnionFind uf(edges.size()+1);
        for (auto e : edges) {
            if (uf.connected(e[0], e[1])) return e;
            else uf.Union(e[0], e[1]);
        }
        return ans;
    }
};


/**
 * @brief Number of Islands
 * 
 * @param grid An nxm 2d binary grid representing a map of 1s and 0s
 * where 1 represents land and 0 represents water.
 * 
 * @return :int: the number of islands. An island is constructed by 
 * linking neighboring areas of land horizontally and vertically
 */
class NumberOfIslands
{
private:
    vector<vector<char>> grid;
public:
    NumberOfIslands(vector<vector<char>>& grid) : grid(grid) {}
    int solve() {
        //* Init a UF
        int n = grid.size(), m = grid[0].size();
        UnionFind UF(n*m);
        //* Count the 1s and setCount
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') count++;
            }
        }
        UF.setCount(count);
        // cout << UF.getCount() << " ";
        //* Traverse the grid again
            // Check if the cur cell is 1 and the upper cell or the left cell is 1 => connect
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;
                if (j > 0) {
                    if (grid[i][j-1] == '1') {
                        UF.Union(i*m + j, i*m + j - 1);
                    }
                }
                if (i > 0) {
                    if (grid[i-1][j] == '1') {
                        UF.Union(i*m + j, (i-1)*m + j);
                    }
                }
            }
        }
        return UF.getCount();
    }
};

#endif // SOLUTION_HPP

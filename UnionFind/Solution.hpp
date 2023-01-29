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
    //? Last Day Where You Can still Cross
    int getTopParent() {
        return find(0);
    }
    int getBottomParent() {
        return find(id.size()-1);
    }
    //? Regions Cut by Slashes
    int getTreeNum() {
        int num = 0;
        for (int i = 0; i < id.size(); i++) {
            if (id[i] == i) num++;
        }
        return num;
    }
    //? Minimum Malware Spread
    int compareHeight(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (heights[rootP] > heights[rootQ]) return p;
        else if (heights[rootP] < heights[rootQ]) return q;
        else {
            if (p > q) return q;
            else return p;
        }
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


/**
 * @brief Last Day Where You Can still Cross
 *  
 * @param cells A based mxn matrix where 0 represents land and 1
 * represents water
 * @param row The matrix rows
 * @param col The matrix columns
 */
class LastDayCanCross
{
private:
    vector<vector<int>> cells;
    int row, col;
    vector<int> offset {0, -1, 0, 1, 0};
public:
    LastDayCanCross(vector<vector<int>>& cells, int row, int col) : 
        cells(cells), row(row), col(col) {}
    int solve() {
        //* Init an union find with 1d row*col+2 array (+1 for top and +1 for bottom connection)
        UnionFind uf(row*col + 2);
        //* Init a grid and mark all cells in it filled with water
        vector<vector<int>> grid(row, vector<int>(col, 1));
        //* Traverse from the last cell in cells
            // Mark the current cell as 0 and find its index: rI*col + cI
            // Check whether it can move in any possible direction. If yes, connect to the current cell
            // Connection with top and bottom row

        // 111
        // 111
        // 011
        int i = cells.size() - 1;
        int rowIndex, colIndex;
        while (i >= 0 && uf.getBottomParent() != uf.getTopParent())
        {
            rowIndex = cells[i][0] - 1;
            colIndex = cells[i][1] - 1;
            grid[rowIndex][colIndex] = 0;
            for (int k = 1; k <= 4; k++) {
                int r = rowIndex + offset[k-1];
                int c = colIndex + offset[k];
                if (r >= 0 && r < row &&
                    c >= 0 && c < col && grid[r][c] == 0) {
                    uf.Union(rowIndex*col+colIndex+1, r*col+c+1);
                }
            }
            if (rowIndex == 0) {
                uf.Union(0, rowIndex*col+colIndex+1);
            }
            else if (rowIndex == row-1) {
                uf.Union(rowIndex*col+col+1, rowIndex*col+colIndex+1);
            }
            i--;
        }
        return i+1;
    }
};


/**
 * @brief Regions Cut by Slashes
 * 
 * @param grid A grid represented as a string array. An nxn grid is composed of
 * 1x1 squares, where each 1x1 square consists of a "/", "\" or a blank space.
 * These characters divide the square into contiguous regions
 * 
 * @return :int: The number of contiguous regions
 */
class RegionsBySlashes
{
private:
    vector<string> grid;
    unordered_map<char,int> directionIndex {
        {'N', 0}, {'W', 1}, {'E', 2}, {'S', 3}
    };
public:
    RegionsBySlashes(vector<string>& grid) : grid(grid) {}
    int solve() {
        int n = grid.size();
        //* Init a 4*n*n union find list (divide a 1x1 box to 4 parts N-E-S-W)
        UnionFind uf(4*n*n);
        //* Traverse the grid, union based on the grid
            // " " => Connect all 4 part
            // "/" => Connect N-W and E-S
            // "\" => Connect N-E and W-S
        int box = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == ' ' || grid[i][j] == '/') {
                    uf.Union(box*4+directionIndex['N'], box*4+directionIndex['W']);
                    uf.Union(box*4+directionIndex['E'], box*4+directionIndex['S']);
                }
                if (grid[i][j] == ' ' || grid[i][j] == '\\') {
                    uf.Union(box*4+directionIndex['N'], box*4+directionIndex['E']);
                    uf.Union(box*4+directionIndex['W'], box*4+directionIndex['S']);
                }
                //* Connect to neighbor boxes
                if (j > 0) {
                    uf.Union(box*4+directionIndex['W'], (box-1)*4+directionIndex['E']);
                }
                // if (j < n - 1) {
                //     uf.Union(box*4+directionIndex['E'], (box+1)*4+directionIndex['W']);
                // }
                if (i > 0) {
                    uf.Union(box*4+directionIndex['N'], (box-n)*4+directionIndex['S']);
                }
                // if (i < n - 1) {
                //     uf.Union(box*4+directionIndex['S'], (box+n)*4+directionIndex['N']);
                // }
                box++;
            }
        }
        //* Count the number of paths
        int ans = uf.getTreeNum();
        return ans;
    }
};


/**
 * @brief Minimize Malware Spread
 * 
 * @param graph A network of n nodes as an n*n adjacency matrix graph, with the ith node
 * directly connected to the jth node if graph[i][j] == 1
 * @param initial Some nodes are infected by a malware at the start. When two nodes are connected 
 * directly and at least one of them is infected, then both nodes will be infected by the malware
 * 
 * @return :int: The node that, when removed from the initial, minimize the final number 
 * of infected nodes with malware
 */
class MinMalwareSpread
{
private:
    vector<vector<int>> graph;
    vector<int> initial;
public:
    MinMalwareSpread(vector<vector<int>>& graph, vector<int> initial) :
        graph(graph), initial(initial) {}
    int solve() {
        //* Construct an union find obj from the graph
        UnionFind uf(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[j].size(); j++) {
                if (graph[i][j] == 1) {
                    uf.Union(i, j);
                }
            }
        }
        //* Traverse the initial 
        //* Get the maximum height from the initial's node
        int ans = initial[0];
        for (int& node : initial) {
            ans = uf.compareHeight(ans, node);
        }
        return ans;
    }
};


/**
 * @brief Evaluate Division
 * 
 * @param equations An array of variable pairs
 * @param values An array of real numbers where the equations[i] = [A[i],B[i]]
 * and values[i] represent the equation values[i] = A[i]/B[i]
 * @param queries An array of input queries, where queries[j] = [C[j],D[j]] 
 * represents the jth query you must find the ans for C[j]/D[j]
 * 
 * @return :vector<double>: the answers for all querires
 */
class EDUnionFind
{
private:
public:
    unordered_map<string, double> weights;
    unordered_map<string, string> id;
    EDUnionFind(vector<vector<string>>& input) {
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[i].size(); j++) {
                if (id.count(input[i][j]) == 0) {
                    id[input[i][j]] = input[i][j];
                    weights[input[i][j]+"-"+input[i][j]] = 1;
                }
            }
        }
    }
    string find(string s) {
        double tmp = 1;
        double reverseTmp = 1;
        string i = s;
        while (id[i] != i) {
            tmp *= weights[id[i]+"-"+i];
            reverseTmp *= weights[i+"-"+id[i]];
            weights[id[i]+"-"+s] = tmp;
            weights[s+"-"+id[i]] = reverseTmp;
            i = id[i];
        }
        return i;
    }
    bool connected(string& p, string& q) {
        return find(p) == find(q);
    }
    void Union(string& dividend, string& divisor, double quotient) {
        weights[dividend+"-"+divisor] = quotient;
        weights[divisor+"-"+dividend] = 1/quotient;
        id[divisor] = dividend;
    }
};

class EvaluateDivision
{
private:
    vector<vector<string>> equations;
    vector<double> values;
    vector<vector<string>> queries;
public:
    EvaluateDivision(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) :
        equations(equations), values(values), queries(queries) {}
    vector<double> solve() {
        vector<double> ans;
        //* Connect the equations together using union find
        EDUnionFind uf(equations);
        for (int i = 0; i < equations.size(); i++) {
            uf.Union(equations[i][0], equations[i][1], values[i]);
        }
        //* Traverse the queries
            // If there is 1 entry is not in the graph ,return -1
            // If the 2 entries are not connected, return -1
            // Otherwise get the ans
        for (auto& entry : queries) {
            if (uf.id.count(entry[0]) == 0 || uf.id.count(entry[1]) == 0) ans.push_back(-1);
            else if (!uf.connected(entry[0], entry[1])) ans.push_back(-1);
            else {
                if (uf.weights.count(entry[0]+"-"+entry[1]) > 0) ans.push_back(uf.weights[entry[0]+"-"+entry[1]]);
                else ans.push_back(-100);
            }
        }
        return ans;
    }
};

#endif // SOLUTION_HPP

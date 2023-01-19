#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

class UnionFind
{
private:
    vector<int> id;
    vector<int> heights;
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            id.push_back(i);
            heights.push_back(1);
        }
    }
    int find(int i) {
        int x = i;
        while (id[i] != i) {
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

#endif // SOLUTION_HPP

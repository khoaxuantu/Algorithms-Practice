#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

class Solution
{
private:
    /*
     * All Tasks Scheduling Orders - prinAllOrders() method
     * -  Used by: printOrder()
     */
    static void printAllOrders(unordered_map<int, vector<int>>& graph,
                               unordered_map<int, int>& inDegree,
                               vector<int>& sources, vector<int>& sortedOrder) {
        // The source vector must not be empty
        // Traverse all the source vector
        if (!sources.empty())
        {
            // Make a copy source vector for next call using (nextCallSources)
            // Remove the curSource out of nextCallSources
            // Push the curSource to sortedOrder
            // Traverse the childs of curSource
                // For each child, decrement the inDegree
                // If the inDegree is 0, push to nextCallSources
            // Call recursively
            // Recover the inDegree of curSource's childs
            for (auto vertex : sources)
            {
                vector<int> nextCallSources (sources);
                nextCallSources.erase(
                    find(nextCallSources.begin(), nextCallSources.end(), vertex)
                );
                sortedOrder.push_back(vertex);

                for (int child : graph[vertex])
                {
                    inDegree[child]--;
                    if (inDegree[child] == 0) nextCallSources.push_back(child);
                }

                printAllOrders(graph, inDegree, nextCallSources, sortedOrder);

                sortedOrder.erase(find(sortedOrder.begin(), sortedOrder.end(), vertex));
                for (int child : graph[vertex])
                {
                    inDegree[child]++;
                }
            }
        }

        // If the sortedOrder == tasks, cout it
        if (sortedOrder.size() == inDegree.size())
        {
            for (int vertex : sortedOrder)
            {
                cout << vertex << " ";
            } cout << endl;
        }
    }

    /* Alien Dictionary - findRule()
     * - Used by findOrder(vector<string>)
     */
    static pair<char, char> findRelation(string str1, string str2) {
        // Traverse each index of 2 strings
        // If the char are diff, return pair
        int i = 0;
        while (i < str1.size() || i < str2.size())
        {
            if (str1[i] != str2[i]) return pair<char, char>(str1[i], str2[i]);
            i++;
        }
        return pair<char, char> {};
    }

public:
    /* Topological Sort */
    static vector<int> sort(int vertices, const vector<vector<int>>& edges)
    {
        vector<int> sortedOrder;
        // TODO: Write your code here
        // Find source vertices
        // Init a map to store number of children of each node
        unordered_map<int, int> parentCount;
        unordered_map<int, vector<int>> child;
        for (auto u : edges)
        {
            if (parentCount.find(u[0]) == parentCount.end())
            {
                parentCount[u[0]] = 0;
            }
            parentCount[u[1]]++;
            child[u[0]].push_back(u[1]);
        }
        // Perform bfs
        // If a node's children is 0 => source, add to the queue
        unordered_set<int> visited;
        queue<int> q;
        for (auto node : parentCount)
        {
            if (node.second == 0)
            {
                q.push(node.first);
            }
        }
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int curNum = q.front();
                q.pop();
                sortedOrder.push_back(curNum);
                visited.insert(curNum);

                for (int child : child[curNum])
                {
                    if (visited.find(child) == visited.end())
                    {
                        visited.insert(child);
                        q.push(child);
                    }
                }
            }
        }
        return sortedOrder;        
    }
    
    /* Tasks Scheduling */
    static bool isSchedulingPossible(int tasks, 
                                     const vector<vector<int>>& prerequisites) 
    {
        // TODO: Write your code here    
        // Find if the tasks are cyclic dependent
        // Construct a graph from the prerequisites
        // If there is no source node, return false
        unordered_map<int, int> parentNodeCount;
        unordered_map<int, vector<int>> graph;
        for (auto p : prerequisites)
        {
            if (parentNodeCount.count(p[0]) == 0)
            {
                parentNodeCount[p[0]] = 0;
            }
            parentNodeCount[p[1]]++;
            graph[p[0]].push_back(p[1]);
        }

        // Perform BFS
        queue<int> q;
        unordered_set<int> visited;
        int nodes = 0;
        for (auto node : parentNodeCount)
        {
            if (node.second == 0) q.push(node.first);
        }
        while (!q.empty())
        {
            if (nodes > parentNodeCount.size()) break;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int curTask = q.front();
                q.pop();

                for (auto child : graph[curTask])
                {
                    if (visited.find(child) == visited.end())
                    {
                        q.push(child);
                        visited.insert(child);
                    }
                }
                nodes++;            
            }
        }
        cout << tasks << " " << parentNodeCount.size() << " " << nodes << endl;
        if (nodes == tasks) return true;
        return false;
    }

    /* Tasks Scheduling Order */
    static vector<int> findOrder(int tasks, const vector<vector<int>>& prerequisites)
    {
        vector<int> sortedOrder;
        // TODO: Write your code here
        // Count the number of each node's parent node
        // Create a graph of tasks
        if (tasks < 0) return sortedOrder;
        unordered_map<int, int> parentNodeCount;
        unordered_map<int, vector<int>> graph;
        for (auto task : prerequisites)
        {
            if (parentNodeCount.find(task[0]) == parentNodeCount.end())
            {
                parentNodeCount[task[0]] = {};
            }
            parentNodeCount[task[1]]++;
            graph[task[0]].push_back(task[1]);
        }
        // Find source node
        // Perform BFS, keep track the number of nodes
        // If there is a cyclic dependency (nodesNum > tasks), return {}
        queue<int> q;
        int tasksTrack = 0;
        for (auto task : parentNodeCount)
        {
            if (task.second == 0)
            {
                q.push(task.first);
            }
        }
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int curTask = q.front();
                q.pop();
                sortedOrder.push_back(curTask);

                for (auto nextTask : graph[curTask])
                {
                    parentNodeCount[nextTask]--;
                    if (parentNodeCount[nextTask] == 0)
                    {
                        q.push(nextTask);
                    }
                }
                tasksTrack++;
                if (tasksTrack > tasks) break;
            }
            if (tasksTrack > tasks) break;
        }
        if (tasksTrack > tasks) return vector<int> {};
        return sortedOrder;
    }

    /* All Tasks Scheduling Orders */
    static void printOrders(int tasks, vector<vector<int>>& prerequisites) {
        vector<int> sortedOrder;
        // TODO: Write your code here
        // Construct a graph
        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> graph;
        for (auto edge : prerequisites)
        {
            if (inDegree.count(edge[0]) == 0) inDegree[edge[0]] = 0;
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        // Find the first sources
        // All sources can be in all orders => store in a vector instead of a queue
        vector<int> sources;
        for (auto node : inDegree)
        {
            if (node.second == 0) sources.push_back(node.first);
        }
        // Call to printAllOrders method
        printAllOrders(graph, inDegree, sources, sortedOrder);
    }

    /* Alien Dictionary */
    static string findOrder(const vector<string> &words) {
        string sortedOrder;
        // TODO: Write your code here
        // How to find which char comes before which char
        // Check 2 continuous words per time, return pair <comesBefore, comesAfter>
        // Construct a graph
        unordered_map<char, int> inDegree;
        unordered_map<char, vector<char>> graph;
        for (int i = 0; i < words.size()-1; i++)
        {
            pair<char, char> relation = findRelation(words[i], words[i+1]);
            if (inDegree.count(relation.first) == 0) inDegree[relation.first] = 0;
            inDegree[relation.second]++;
            graph[relation.first].push_back(relation.second);
        }

        // Perform BFS and push to sortedOrder
        queue<char> q;
        for (auto vertex : inDegree)
        {
            if (vertex.second == 0)
            {
                q.push(vertex.first);
            }
        }
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                char curVertex = q.front();
                q.pop();
                sortedOrder += curVertex;

                for (char child : graph[curVertex])
                {
                    inDegree[child]--;
                    if (inDegree[child] == 0)
                    {
                        q.push(child);
                    }
                }
            }
        }
        return sortedOrder;
    }

    /* Reconstructing a Sequence */
    static bool canConstruct(const vector<int> &originalSeq,
                             const vector<vector<int>> &sequences) {
        // TODO: Write your code here
        // Construct a graph from sequences vector
        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> graph;
        for (auto seq : sequences)
        {
            for (int i = 0; i < seq.size()-1; i++)
            {
                if (inDegree.count(seq[i]) == 0) inDegree[seq[i]] = 0;
                inDegree[seq[i+1]]++;
                graph[seq[i]].push_back(seq[i+1]);
            }
        }
        if (inDegree.size() != originalSeq.size()) return false;
        // Find the source vertex, if more than 1 => return false
        // Perform BFS
        // If the queueSize > 1 => false
        vector<int> log;
        queue<int> q;
        for (auto vertex : inDegree)
        {
            if (vertex.second == 0) q.push(vertex.first); 
        }
        while (!q.empty())
        {
            int size = q.size();
            if (size > 1) return false;
            if (originalSeq[log.size()] != q.front()) return false;
            for (int i = 0; i < size; i++)
            {
                int curVertex = q.front();
                q.pop();
                log.push_back(curVertex);
                for (int child : graph[curVertex])
                {
                    inDegree[child]--;
                    if (inDegree[child] == 0) q.push(child);
                }
            }
        }
        for (int n : log)
        {
            cout << n << " ";
        }cout << endl;
        return log.size() == originalSeq.size();
    }

    /* Minimum Height Trees */
    static vector<int> findTrees(int nodes, vector<vector<int>>& edges)
    {
        vector<int> minHeightTrees;
        // TODO: Write your code here
        // Construct a graph
        unordered_map<int, int> degree;
        unordered_map<int, vector<int>> graph;
        for (auto u : edges)
        {
            degree[u[0]]++;
            degree[u[1]]++;
            graph[u[0]].push_back(u[1]);
            graph[u[1]].push_back(u[0]);
        }
        
        // Set each vertex to be the source node
        // Perform BFS to count the tree height, store the height in a map
        // Keep track the minimum height
        int minHeight = nodes;
        unordered_map<int, vector<int>> heightMap; // <height, tree root>
        queue<int> q;
        for (auto vertex : graph)
        {
            int heightTracking = 0;
            q.push(vertex.first);
            // Reset the degree of the source node to 0
            degree[vertex.first] = 0;
            while (!q.empty())
            {
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    int u = q.front();
                    q.pop();
                    for (auto child : graph[u])
                    {
                        // degree[child]--;
                        if (degree[child] != 0)
                        {
                            q.push(child);
                            degree[child] = 0;
                        }
                    }
                }
                heightTracking++;
            }
            // Recover the degree of every edges for next tree
            for (auto u : edges)
            {
                degree[u[0]]++;
                degree[u[1]]++;
            }
            heightMap[heightTracking].push_back(vertex.first);
            minHeight = min(heightTracking, minHeight);
        } 
        // Add all the source vertex which create MHT to ans
        for (int source : heightMap[minHeight])
        {
            minHeightTrees.push_back(source);
        }
        return minHeightTrees;
    }
};


#endif // SOLUTION_HPP

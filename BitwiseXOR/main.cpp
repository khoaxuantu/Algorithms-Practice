#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    static void swap(vector<int>& arr, int a, int b)
    {
        int tmp = arr[a]^1;
        arr[a] = arr[b]^1;
        arr[b] = tmp;
    }

public:
    static vector<vector<int>> solve(vector<vector<int>>& arr)
    {
        // TODO: Write your code here
        int start = 0, end = arr[0].size()-1;
        while (start <= end)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                if (start != end)
                {
                    swap(arr[i], start, end);
                }
                else arr[i][start] ^= 1;
            }
            start++;
            end--;
        }
        return arr;
    }

    static void print(const vector<vector<int>> arr) {
      for(int i=0; i < arr.size(); i++) {
        for (int j=0; j < arr[i].size(); j++) {
          cout << arr[i][j] << " ";
        }
        cout << endl;
      }
    }
};

int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    
    vector<vector<int>> arr = vector<vector<int>>{{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
    Solution::print(Solution::solve(arr));
    cout << endl;

    vector<vector<int>> arr2 = vector<vector<int>>{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    Solution::print(Solution::solve(arr2));
    
    /* End timing */
    end = clock();
    
    /* Print out time */
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " ms " << endl;
    cout << endl;
    return 0;
}

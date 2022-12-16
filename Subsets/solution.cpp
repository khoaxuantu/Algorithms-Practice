using namespace std;

#include<bits/stdc++.h>

class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    // start by adding the empty subset
    subsets.push_back(vector<int>());
    for (auto currentNumber : nums) {
      // we will take all existing subsets and insert the current number in them to create new
      // subsets
      int n = subsets.size();
      for (int i = 0; i < n; i++) {
        // create a new subset from the existing subset and insert the current element to it
        vector<int> set(subsets[i]);
        set.push_back(currentNumber);
        subsets.push_back(set);
      }
    }
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  /* Start and end timing */
  clock_t start, end;
  
  /* Start timing */
  start = clock();
  
  vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = Subsets::findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
  
  
  /* End timing */
  end = clock();
  
  /* Print out time */
  double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
  cout << "Time taken by program is : " << fixed 
       << time_taken << setprecision(5);
  cout << " ms " << endl;
  cout << endl;
}

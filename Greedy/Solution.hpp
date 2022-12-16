#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

#define PAIR pair<int,int>
class Solution 
{
private:
public:
    /* Jump Game */
    bool JumpGame(vector<int>& nums) {
        // * Traverse the nums from the left
            // Find a reachable preceding index and make it a new target
            // If reach the first index without finding any target, return false
        if (nums.size() <= 1) return true;
        int i = nums.size() - 1;
        int target = i;
        while (i >= 0) {
            if (nums[i] + i >= target) {
                target = i;
            }
            if (i == 0 && target != i) return false;
            i--;
        }
        return true;
    }

    /* Boats to Save People */
    int RescueBoats(vector<int>& people, int limit) {
        int start = 0, end = people.size()-1;
        int count = 0;
        // * Sort the people from lightest to heaviest
        sort(people.begin(), people.end());
        // * Init 2 ptr start and end
        // * Traverse the array until start >= end
            // If people[start] + people[end] <= limit, increment start
            // decrement end
            // Increment count
        while (start <= end)
        {
            if (people[start] + people[end] <= limit) {
                start++;
            }
            end--;
            count++;
        }
        return count;
    }

    /* Gas Stations */
    int GasStationJourney(vector<int>& gas, vector<int> cost) {
        // * Condition to be able to move to next gas station: carriedGas >= cost
        // If totalGas < totalCost, return -1
        int size = gas.size();
        int totalGas=0, totalCost=0;
        for (int i = 0; i < size; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if (totalGas < totalCost) return -1;
        int carriedGas = 0;
        int startingIndex = 0;
        // Try every gas station, i = (i+1)%size
        // If carriedGas + gas >= cost, update carriedGas
            // If carriedGas == 0, return starting index
        // Else, reset carriedGas to 0
            // Update the starting index
        int i = startingIndex;
        int iter = 0;
        while (startingIndex < size)
        {
            if (carriedGas + gas[i] >= cost[i]) {
                carriedGas += gas[i] - cost[i];
                i = (i+1) % size;
                if (i == startingIndex) break;
            }
            else {
                carriedGas = 0;
                startingIndex++;
                i = startingIndex;
            }
            iter++;
        }
        // cout << iter << " ";
        return startingIndex;
    }

    /* Two City Scheduling */
    int TwoCityScheduling(vector<PAIR>& costs) {
        // TODO: Select cost.length/2 people going to A, and another cost.length/2 going to B
        // Init an array to store the extra amount each person go to B instead of A
        // Sort the array
        vector<pair<int, PAIR>> arr;
        for (auto person : costs) {
            arr.push_back(make_pair(person.second-person.first, person));
        }
        sort(arr.begin(), arr.end(), [](pair<int, PAIR>& x, pair<int, PAIR>& y){
            return x.first < y.first;
        });
        int ans = 0;
        // Store the bCost of the first half, and the aCost of the second half
        for (int i = 0; i < arr.size(); i++) {
            if (i < arr.size()/2) {
                ans += arr[i].second.second;
            }
            else ans += arr[i].second.first;
            cout << arr[i].second.first<<","<<arr[i].second.second<<" ";
        } cout << "| ";
        return ans;
    }

    /* Jump Game II */
    int JumpGameTwo(vector<int>& nums) {
        // Init curJump, farthestJump
        // @param farthestJump the farthest index that the curJump can reach
        int ans = 0;
        int curJump = 0, farthestJump = 0;
        // Traverse the array
            // Update the farthestJump
            // If curJump == i, update the curJump and increment jumps
        for (int i = 0; i < nums.size(); i++) {
            farthestJump = max(farthestJump, nums[i] + i);
            if (curJump == i && i < nums.size() - 1) {
                ans++;
                curJump = farthestJump;
            }
        }
        return ans;
    }
};

#endif // SOLUTION_HPP

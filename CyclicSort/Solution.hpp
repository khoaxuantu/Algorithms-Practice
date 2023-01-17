#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

class Swap
{
public:
    static void arrSwap(vector<int> &nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};

/**
 * @brief Cyclic Sort
 * 
 * @param nums An array containing n objects. Each object, when created, 
 * was assigned a unique number from the range 1 to n based on their creation sequence. 
 * This means that the object with sequence number 3 was created just before 
 * the object with sequence number 4.
 * 
 * @param :vector<int>: Sort the objects in-place on their creation sequence number
 * in O(n) and without using any extra space
 */
class CyclicSort
{
private:
    vector<int> nums;
public:
    CyclicSort(vector<int>& arr) : nums(arr) {}
    void solve() {
        // TODO: Write your code here 
        int index = 0;
        while (index < nums.size())
        {
            if (nums[index] != nums[nums[index] - 1])
            {
                Swap::arrSwap(nums, index, nums[index]-1);
            }
            else
            {
                index++;
            }
        }
    }
};


/**
 * @brief Find all Missing Numbers
 * 
 * @param nums An unsorted array array containing numbers taken from 
 * the range 1 to n 
 * 
 * @return :vector<int>: All the missing numbers
 */
class AllMissingNumbers
{
private:
    vector<int> nums;
public:
    AllMissingNumbers(vector<int>& nums) : nums(nums) {}
    vector<int> solve() {
        vector<int> missingNumbers;
        // TODO: Write your code here
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == nums[nums[i]-1])
            {
                i++;
            }
            else
            {
                Swap::arrSwap(nums, i, nums[i]-1);
            }
        }
        // Traverse again to find the missing num
        for (int num = 0; num < nums.size(); num++)
        {
            cout << num << ":" << nums[num] << " ";
            if (nums[num] != num + 1) missingNumbers.push_back(num+1);
        }
        cout << endl;
        return missingNumbers;
    }
};


/**
 * @brief Find the Duplicate Numbers
 * 
 * @param nums An unsorted array containing 'n+1' numbers taken from 
 * the range 1 to n. The array has only 1 duplicate but it can be repeated
 * multiple times 
 * 
 * @return :int: Find the duplicate number without using any extra space
 */
class FindDuplicate
{
private:
    vector<int> nums;
public:
    FindDuplicate(vector<int>& nums) : nums(nums) {}
    int solve() {
        // TODO: Write your code here
        // Sort the arr to appropriate index
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            {
                Swap::arrSwap(nums, i, nums[i] - 1);
            }
            else
            {
                i++;
            }
        }
        
        // Find the duplicate
        for (i = 0; i < nums.size(); i++)
        {
            // cout << i << ":" << nums[i] << " ";
            if (nums[i] != i + 1 && nums[i] == nums[nums[i] - 1]) return nums[i];
        }
        return -1;
    }
};


/**
 * @brief Find all Duplicate Numbers
 * 
 * @param nums An unsorted array containing n numbers taken from the
 * range 1 to n. The array has some numbers appearing twice.
 * 
 * @return :vector<int>: Find all the duplicate numbers using constant space
 */
class FindAllDuplicates
{
private:
    vector<int> nums;
public:
    FindAllDuplicates(vector<int>& nums) : nums(nums) {}
    vector<int> solve() {
        vector<int> duplicateNumbers;
        // TODO: Write your code here
        // Sort the arr to appropriate index
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] != i + 1)
            {
                if (nums[i] != nums[nums[i] - 1])
                {
                    Swap::arrSwap(nums, i, nums[i] - 1);
                }
                else
                {
                    duplicateNumbers.push_back(nums[i]);
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        for (i = 0; i < nums.size(); i++)
        {
          cout << nums[i] << " ";
        }
        cout << endl;
        return duplicateNumbers;
    }
};


/**
 * @brief Find the Corrupted Pair
 * 
 * @param nums An unsorted array containing n numbers taken from the range
 * 1 to n. The array originally contained all the numbers from 1 to n, but
 * due to a data error, one of the numbers got duplicated which also resulted
 * in one number missing
 * 
 * @return :vector<int>: Find both the missing number and the duplicate number
 */
class FindCorruptNums 
{
private:
    vector<int> nums;
public: 
    FindCorruptNums(vector<int>& nums) : nums(nums) {}
    vector<int> solve() {
        // TODO: Write your code here
        vector<int> ans;
        // Place the number into correct index
        // i : val (val = i + 1)
        // Run through the nums
            // For each num, 
            // If the val is not in correct index, swap with the correct index of the val
                // If found the duplicate, push into ans the val and the index + 1
            // Else skip it
        int i = 0;
        while (i < nums.size()) // 1 2 3 3 6 4
        {
            if (nums[i] != nums[nums[i] - 1])
            {
                Swap::arrSwap(nums, i , nums[i] - 1);
            }
            else
            {
                i++;
            }
        }

        for (i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
            if (i + 1 != nums[i] && nums[i] == nums[nums[i] - 1])
            {
                ans.push_back(nums[i]);
                ans.push_back(i + 1);
            }
        }
        if (ans.size() == 0)
        {
          return vector<int> {-1, -1};
        }
        cout << endl;
        return ans;
    }
};


/**
 * @brief Find the Smallest Missing Positive Number
 * 
 * @param nums An unsorted array containing numbers
 * 
 * @return :int: The smallest missing positive number
 */
class FirstSmallestMissingPositive
{
private:
    vector<int> nums;
    bool findZero(vector<int>& nums)
    {
        for (auto num : nums)
        {
            if (num == 0) return true;
        }
        return false;
    }
public:
    FirstSmallestMissingPositive(vector<int>& nums) : nums(nums) {}
    int solve() {
        // TODO: Write your code here
        int ans = -1;
        // Find if the nums included 0
        bool haveZero = findZero(nums);
        // Place each num into the correct index
            // Take the correct based on Zero or nonZero
            // Check if the val is in the correct index or not
            // If not then move to the next index
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] < 0 || nums[i] >= nums.size()) i++;
            int j = haveZero ? nums[i] : nums[i] - 1;
            if (nums[i] != nums[j])
            {
                Swap::arrSwap(nums, i, j);
            }
            else
            {
                i++;
            }
        }
        
        // Traverse the nums again and find the missing num 
        for (i = 0; i < nums.size(); i++)
        {
            // cout << nums[i] << " ";
            int j = haveZero ? nums[i] : nums[i] - 1;

            if (nums[i] != nums[j]) ans = haveZero ? i : i + 1;
        }
        // cout << endl;
        return ans;
    }
};


/**
 * @brief Find the First K Missing Positive Numbers
 * 
 * @param nums An unsorted array containing numbers
 * @param k A number 'K'
 * 
 * @return :vector<int>: The first 'K' missing positive numbers in nums
 */
class FirstKMissingPositive
{
private:
    vector<int> nums;
    int k;
public:
    FirstKMissingPositive(vector<int>& nums, int k) : nums(nums), k(k) {}
    vector<int> solve() {
        vector<int> missingNumbers;
        // TODO: Write your code here
        for (int n = 0; n < k; n++)
        {
            nums.push_back(0);
        }
        
        // Place each num into the correct index
            // Take the correct based on Zero or nonZero
            // Check if the val is in the correct index or not
            // If not then move to the next index
        int i = 0;
        while (i < nums.size())
        {
            // int j = haveZero ? nums[i] : nums[i] - 1;
            int j = nums[i] - 1;
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[j])
            {
                Swap::arrSwap(nums, i, j);
            }
            else
            {
                i++;
            }
        }
        
        // Traverse the nums again and find the missing num 
        for (i = 0; i < nums.size(); i++)
        {
            // cout << nums[i] << " ";
            // int j = haveZero ? nums[i] : nums[i] - 1;
            if (nums[i] != i + 1 && missingNumbers.size() < k)
            {
                missingNumbers.push_back(i + 1);
            }
        }
        // cout << endl;
        return missingNumbers;
    }
};

#endif // SOLUTION_HPP

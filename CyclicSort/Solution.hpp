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

#endif // SOLUTION_HPP

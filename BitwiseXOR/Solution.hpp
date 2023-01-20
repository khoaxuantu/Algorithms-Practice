#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Single Number
 * 
 * @param arr A non-empty array of integers, every number appears
 * twice except for one
 * 
 * @return :int: The single number
 */
class SingleNumber 
{ 
private:
    vector<int> arr;
public:
    SingleNumber(vector<int>& arr) : arr(arr) {}
    int solve() {
        // TODO: Write your code here
        int ans = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            ans ^= arr[i];  
        }
        return ans;
    }
};


/**
 * @brief Two Single Number
 * 
 * @param nums A non-empty array of numbers, every number appears 
 * exactly twice except two numbers that appear only once
 * 
 * @return :vector<int>: The two numbers that appear only once
 */
class TwoSingleNumbers
{
private:
    vector<int> nums;
public:
    TwoSingleNumbers(vector<int>& nums) : nums(nums) {}
    vector<int> solve() {
        // TODO: Write your code here
        int rightMostBit = 1;
        int num1 = 0, num2 = 0;
        // Get XOR of all num
        int n1n2 = 0;
        for (int n : nums)
        {
            n1n2 ^= n;
        }
        // Get the right most bit that is 1 in the XOR
        while ((rightMostBit & n1n2) == 0)
        {
            rightMostBit = rightMostBit << 1;
        }
        // Partition XOR to num1 and num2
        // num1 for rightmost 1
        // num2 for rightmost not 1
        // return num1 num2
        for (int num : nums)
        {
            if ((rightMostBit & num) == 0)
            {
                num2 ^= num;
            }
            else num1 ^= num;
        }
        return {num1, num2};
    }
};


/**
 * @brief Complement of Base 10 Number
 * 
 * @param n A non-negative integer
 * 
 * @return :int: The compliment of n's binary representation
 * as a base-10 integer
 */
class CalculateComplement
{
private:
    int n;
public:
    CalculateComplement(int n) : n(n) {}
    int solve() {
        // TODO: Write your code here
        int bitToChange = pow(2, 7);
        bool meetFirstOne = false;
        for (int i = 0; i < 8; i++)
        {
            if (!meetFirstOne)
            {
                if ((bitToChange & n) != 0)
                {
                    n ^= bitToChange;
                    meetFirstOne = true;
                }
            }
            else
            {
                n ^= bitToChange;
            }
            bitToChange = bitToChange >> 1;
        }
        return n;
    }
};


/**
 * @brief Flip and Invert Image 
 * 
 * @param arr A binary matrix representing an image
 * 
 * @return :vector<vector<ing>>: The image after being flipped horizontally
 * then inverted
 */
class FlipAndInvertImage
{
private:
    vector<vector<int>> arr;
    void swap(vector<int>& arr, int a, int b)
    {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
public:
    FlipAndInvertImage(vector<vector<int>>& arr) : arr(arr) {}
    vector<vector<int>> solve() {
        //TODO: Write your code here
        // TODO: Write your code here
        int start = 0, end = arr[0].size()-1;
        while (start <= end)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                if (start != end)
                {
                    swap(arr[i], start, end);
                    arr[i][start] ^= 1;
                }
                arr[i][end] ^= 1;
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

#endif // SOLUTION_HPP

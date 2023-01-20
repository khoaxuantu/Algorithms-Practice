#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Order-agnostic Binary Search
 * 
 * @param arr A sorted array of number
 * @param key A given number 'key' presented in the array
 * 
 * @return :int: the index of the 'key' if it is present in the array,
 * otherwise return -1
 */
class OrderagnosticBinarySearch 
{
private:
    vector<int> arr;
    int key;
    int binarySearch(const vector<int>& arr, int key, int start, int end, const vector<int>& initArr)
    {
        if (start > end) return -1;
        int mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            if (initArr[0] > initArr[initArr.size() - 1])
            {
                return initArr.size() - 1 - mid;
            }
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binarySearch(arr, key, start, mid - 1, initArr);
        }
        else
        {
            return binarySearch(arr, key, mid + 1, end, initArr);
        }
    }
public:
    OrderagnosticBinarySearch(vector<int>& arr, int key) : arr(arr), key(key) {}
    int search() {
        // TODO: Write your code here
        vector<int> arrCopy (arr);
        sort(arrCopy.begin(), arrCopy.end());
        return binarySearch(arrCopy, key, 0, arrCopy.size() - 1, arr);
    }
};


/**
 * @brief Ceiling of a Number
 * 
 * @param arr An array of number sorted in an ascending order
 * @param key A given number 'key'
 * 
 * @return :int: the index of the ceiling of the 'key. If there isn't any ceiling return -1
 */
class CeilingOfANumber
{
private:
    vector<int> arr;
    int key;
public:
    CeilingOfANumber(vector<int>& arr, int key) : arr(arr), key(key) {}
    int solve() {
        // TODO: Write your code here
        int start = 0;
        int end = arr.size() - 1;
        int mid;
        bool firstLv = true;
        while (start <= end)
        {
            // Check if the key is out of range of the arr in the first iter
            if (firstLv)
            {
                if (arr[end] < key) return -1;
                if (arr[start] >= key) return 0;
            }
            // If not then find inside the arr
            mid = start + (end - start) / 2;

            if (arr[mid] == key || start == end)
            {
                return mid;
            }
            else if (arr[mid] > key)
            {
                end = mid - 1;
            }
            else 
            {
                start = mid + 1;
            }
            firstLv = false;
        }
        return -1;
    }
};


/**
 * @brief Next Letter
 * 
 * @param letters An array of lowercase letters sorted in 
 * ascending order
 * @param key A given key character
 * 
 * @return :char: The smallest letter in the given array greater than
 * a given key
 */
class NextLevel
{
private:
    vector<char> letters;
    char key;
public:
    NextLevel(vector<char>& letters, char key) : letters(letters), key(key) {}
    char solve() {
        // TODO: Write your code here
        int start = 0, end = letters.size() - 1;
        // If the letter is outside the scope, return first letter for larger or
        // last letter for lower
        if (key >= letters[end] || key <= letters[start]) return letters[0];
        // Search the letters
        // If meets the key, return the next letter
        // If mid is larger than key, update end
        // If mid is lower than key, update start
        while (start <= end)
        {
            int mid = start + (end - start)/2;
            if (letters[mid] == key)
            {
                if (mid == letters.size()-1) return letters[0];
                else return letters[mid+1];
            }
            else if (letters[mid] > key)
            {
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return letters[start];
    }
};


/**
 * @brief Next Letter
 * 
 * @param arr An array of number sorted in an ascending order
 * @param key A given number 'key'
 * 
 * @return :pair<int,int>: the range of the 'key'
 */
class FindRange
{
private:
    vector<int> arr;
    int key;
public:
    FindRange(vector<int>& arr, int key) : arr(arr), key(key) {}
    pair<int,int> solve() {
        pair<int, int> result(-1, -1);
        // TODO: Write your code here
        // If the key is out of scope, return -1, -1
        int n = arr.size();
        int start = 0, end = n - 1; 
        if (key > arr[n - 1] || key < arr[0]) return result;
        // Find a key in the arr first
        // After find out, find on the left and right to store the range
        while (start <= end)
        {
            int mid = start + (end - start)/2;

            if (arr[mid] == key)
            {
                result = make_pair(mid, mid);
                int sRange = mid, eRange = mid;
                while (sRange >= 0 && arr[sRange] == key)
                {
                    sRange--;
                }
                result.first = min(result.first, sRange+1);
                while (eRange < n && arr[eRange] == key)
                {
                    eRange++;
                }
                result.second = max(result.second, eRange-1);
                break;
            }
            else if (arr[mid] > key)
            {
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return result;
    }
};


/**
 * @brief Minimum Difference Element
 * 
 * @param arr An array of number sorted in an ascending order
 * @param key A given number 'key'
 * 
 * @return :int: The element in the array that has the minimum difference
 * with the given 'key'
 */
class MinimumDifference
{
private:
    vector<int> arr;
    int key;
public:
    MinimumDifference(vector<int>& arr, int key) : arr(arr), key(key) {}
    int solve() {
        // TODO: Write your code here
        // If the key is out of scope, return max num or min num in arr
        int n = arr.size();
        int start = 0, end = n - 1;
        if (key < arr[start]) return arr[start];
        if (key > arr[end]) return arr[end];
        // Perform the binary search
        // If the key is met then return key
        // If is not met, compare between start-key and end-key
            // Return the closer
        while (start <= end)
        {
            int mid = start + (end - start)/2;

            if (arr[mid] == key) return key;
            else if (arr[mid] > key)
            {
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        if (abs(arr[start] - key) > abs(arr[end] - key))
        {
            return arr[end];
        }
        else return arr[start];
        return -1;
    }
};


/**
 * @brief Bitonic Array Maximum
 * 
 * @param arr A given Bitonic array. An array is considered bitonic 
 * if it is monotonically increasing and then monotonically decreasing
 * 
 * @return :int: Maximum value in the array
 */
class MaxInBitonicArray
{
private:
    vector<int> arr;
public:
    MaxInBitonicArray(vector<int>& arr) : arr(arr) {}
    int solve() {
        // TODO: Write your code here
        int start = 0, end = arr.size()-1;
        // Cal mid
            // if end = start, return arr[mid]
            // else If arr[mid+1] > arr[mid], update start
            // Else if arr[mid - 1] > arr[mid], update end
        while (start <= end)
        {
            int mid = start + (end-start)/2;

            if (end == start || (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])) 
            {
                return arr[mid];
            }
            else if (arr[mid+1] > arr[mid])
            {
                start = mid + 1;
            }
            else if (arr[mid - 1] > arr[mid]) end = mid - 1;
        }
        return -1;
    }
};


/**
 * @brief Search Bitonic Array
 * 
 * @param arr An array of number sorted in an ascending order
 * @param key A given number 'key'
 * 
 * @return :int: The index of the 'key'. If the key is not present, return -1
 */
class SearchBitonicArray
{
private:
    vector<int> arr;
    int key;
    int findPeak(const vector<int>& arr)
    {
        int start = 0, end = arr.size() - 1;
        while (start < end)
        {
            int mid = start + (end-start)/2;

            if (arr[mid] > arr[mid+1])
            {
                end = mid;
            }
            else start = mid + 1;
        }
        return start;
    }
public:
    SearchBitonicArray(vector<int>& arr, int key) : arr(arr), key(key) {}
    int solve() {
        // TODO: Write your code here
        // Find out the index of the peak point
        int peak = findPeak(arr);
        if (arr[peak] == key) return peak;
        // Search for the key in the ascending part and the descending part
        int mid;
        int start = 0, end = peak-1;
        while (start <= end)
        {
            mid = start + (end-start)/2;
            if (arr[mid] == key) return mid;
            else if (arr[mid] > key) end = mid-1;
            else start = mid+1;
        }
        
        start = peak+1, end = arr.size()-1;
        while (start <= end)
        {
            mid = start + (end-start)/2;
            if (arr[mid] == key) return mid;
            else if (arr[mid] > key) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
};


/**
 * @brief Search in Rotated Array
 * 
 * @param arr An array of number sorted in an ascending order
 * @param key A given number 'key'
 * 
 * @return :int: The index of the 'key' in the rotated array 
 */
class SearchRotatedArray
{
private:
    vector<int> arr;
    int key;
    int findBreakpoint (const vector<int>& arr)
    {
        int start = 0, end = arr.size()-1;
        int mid;
        while (start < end)
        {
            mid = start + (end-start)/2;
            
            if (arr[mid] < arr[end])
            {
                end = mid;
            }
            else start = mid+1;
        }
        return start;
    }
    int binarySearch(const vector<int>& arr, int key, int start, int end)
    {
        int mid;
        while (start <= end)
        {
            mid = start + (end-start)/2;
            if (arr[mid] == key) return mid;
            else if (arr[mid] > key) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
public:
    SearchRotatedArray(vector<int>& arr, int key) : arr(arr), key(key) {}
    int solve() {
        // TODO: Write your code here
        int ans;
        int n = arr.size();
        bool rotated = arr[0] > arr[n-1] ? true : false;
        // If rotated
        // Find the breakpoint (the before-rotated first element)
        // Perform binary search in both halves
        int breakpoint = n - 1;
        if (rotated) breakpoint = findBreakpoint(arr);
        
        ans = binarySearch(arr, key, 0, breakpoint-1);
        if (ans != -1) return ans;
        ans = binarySearch(arr, key, breakpoint, n-1);
        return ans;
    }
};


/**
 * @brief Rotation Count
 * 
 * @param arr An array of numbers which is sorted in ascending order amd 
 * is rotated 'k' times around a pivot
 * 
 * @return :int: The 'k' 
 */
class RotationCountOfRotatedArray
{
private:
    vector<int> arr;
public:
    RotationCountOfRotatedArray(vector<int>& arr) : arr(arr) {}
    int solve() {
        // TODO: Write your code here
        // If the first element is larger than the last one, return 0
        int start = 0, end = arr.size() - 1;
        if (arr[start] < arr[end]) return 0;
        // Perform the binary search pattern

        // Take start, end
            // Cal mid
            // If mid <= end, mid = end
            // IF mid > end, mid = start
        int mid;
        while (start < end)
        {
            mid = start + (end-start)/2;

            if (arr[mid] <= arr[end]) end = mid;
            else start = mid+1;
        }
        
        return start;
    }
};

#endif // SOLUTION_HPP

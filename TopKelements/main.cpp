#include <bits/stdc++.h>

// #include "../Header/Point.hpp"

using namespace std;

class Element
{
private:
public:
    int val=0, freq=0, order=0;
    Element(int val, int frequency, int sequence)
    {
        this->val = val;
        this->freq = frequency;
        this->order = sequence;
    }
};


class Solution
{
private:
    int order = 0;
    // unordered_map<int,int> sequenceNum;
    // Num: freq
    queue<Element> cache;
    unordered_map<int, int> numMap;
    
    struct custCmp {
        bool operator()(const Element& x, const Element& y)
        {
            if (x.freq != y.freq)
            {
                return x.freq < y.freq;
            }
            return x.order < y.order;
        }
    };
    priority_queue<Element, vector<Element>, custCmp> maxHeap;

public:
    static int solve(const vector<char>& arr, int k)
    {
        int intervalCount = 0;
        // TODO: Write your code here
        
        return intervalCount;
    }

    void printHeap()
    {
        priority_queue<Element, vector<Element>, custCmp> copyHeap(maxHeap);
        while (!copyHeap.empty())
        {
            cout << copyHeap.top().val << ":" << copyHeap.top().freq << ":" << copyHeap.top().order << " ";
            copyHeap.pop();
        }
    }

    void push(int num)
    {
        // Take the order 
        order++;
        // sequenceNum[num] = order;

        numMap[num]++;
        maxHeap.push(Element(num, numMap[num], order));
    }

    int pop()
    {
        auto mostFreqNum = maxHeap.top();
        maxHeap.pop();

        if (numMap[mostFreqNum.val] > 1)
        {
            numMap[mostFreqNum.val]--;
        }
        else numMap.erase(mostFreqNum.val);
        
        this->printHeap();
        return mostFreqNum.val;
    }

};

int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    
    Solution frequencyStack;
    frequencyStack.push(1);
    frequencyStack.push(2);
    frequencyStack.push(3);
    frequencyStack.push(2);
    frequencyStack.push(1);
    frequencyStack.push(2);
    frequencyStack.push(5); // 2:3 1:2 3:1 5:1
    frequencyStack.printHeap();
    cout << endl;
    cout << frequencyStack.pop() << endl;
    cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
    cout << frequencyStack.pop() << endl;
    
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

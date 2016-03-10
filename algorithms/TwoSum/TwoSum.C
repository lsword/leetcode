#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> um;
        for (int i=0; i<nums.size(); ++i) {
            if (um.find(nums[i])==um.end()) {
                um[target-nums[i]] = i;
            }
            else {
                result.push_back(um[nums[i]]);
                result.push_back(i);
            }
        }
        return result;
    }
};

void printVector(vector<int> &vec) {
    vector<int>::iterator vi;
    for (vi=vec.begin(); vi != vec.end(); ++vi) {
        cout << *vi << ", " ;
    }
    cout << endl;
}

int main() {
    int a[] = {0, 1, 2, 3};
    vector<int> numbers(a, a+sizeof(a)/sizeof(int));
    int target = 3;

    vector<int> result;

    Solution s;
    result = s.twoSum(numbers, target);

    printVector(result);

	return 0;
}

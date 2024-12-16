#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> nums = {2, 1, 5, 6, 2, 3};
    vector<int> nextGreater = nextGreaterElement(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " -> " << nextGreater[i] << endl;
    }

    return 0;
}
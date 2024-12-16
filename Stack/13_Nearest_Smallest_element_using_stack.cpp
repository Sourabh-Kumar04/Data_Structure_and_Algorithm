#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[i] <= nums[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = nums[s.top()];
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> nextSmaller = nextSmallerElement(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " -> " << nextSmaller[i] << endl;
    }

    return 0;
}
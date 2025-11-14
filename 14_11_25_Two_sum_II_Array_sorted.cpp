//Description:
/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
*/

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        vector<int>result(2);
        while(left<right){
            int temp=numbers[left]+numbers[right];
            if(temp==target){
                result[0]=left+1;
                result[1]=right+1;
                return result;
            }
            else if(temp>target){
                right--;
            }
            else{
                left++;
            }
        }
        return {};
    }
};
int main(){
    int n,target;
    cin >> n >> target;
    vector<int>numbers(n);
    for(int i=0;i<n;i++)cin >> numbers[i];
    Solution sol;
    vector<int>res=sol.twoSum(numbers,target);
    if(res.empty()){
        cout << "No solution" << endl;
    } else {
        cout <<'['<< res[0] << ' ' << res[1] <<']'<< endl;
    }
}

//my logic:
/*
 Since the array is already sorted, I used the two-pointer technique to find the two numbers that add up to the target. I initialized one pointer at the start (left) and another at the end (right) of the array. I then calculated the sum of the numbers at these two pointers. If the sum equals the target, I returned their indices (adjusted for 1-based indexing). If the sum is greater than the target, I moved the right pointer one step to the left to decrease the sum. If the sum is less than the target, I moved the left pointer one step to the right to increase the sum. This process continued until I found the two numbers.
*/
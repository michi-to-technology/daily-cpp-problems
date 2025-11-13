//Description

/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

//my logic:
/*
 I used the unordered_map to store the elements of the array as we iterate through it
 along with their indices. For each element, I calculated its complement (target - current element) 
 and checked if this complement exists in the map. If it does, I returned the indices of the current element and its complement.
  If not, I added the current element and its index to the map and continued iterating through the array. 
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int>&nums,int target){
    unordered_map<int,int>ump;
    for(int i=0;i<nums.size();i++){
        int x=nums[i];
        int y=target-x;
        if(ump.count(y)){
            return {ump[y],i};
        }
        else{
            ump[x]=i;
        }
    }
    return {};
}
int main(){
    int n,target;;
    cin >> n >> target;
    vector<int>num(n);
    for(int i=0;i<n;i++) cin >> num[i];
    {
        vector<int> res = twosum(num, target);
        if(res.empty()){
            cout << "No solution" << endl;
        } else {
            cout <<'['<< res[0] << ' ' << res[1] <<']'<< endl;
        }
    }
    return 0;
}
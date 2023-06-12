#include <bits/stdc++.h>
 
using namespace std;
 
// function to count subarrays with
// equal number of 1's and 0's
int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    // 'um' implemented as hash table to store
    // frequency of values obtained through
    // cumulative sum
    unordered_map<int, int> um;
    int curr_sum = 0;
 
    // Traverse original array and compute cumulative
    // sum and increase count by 1 for this sum
    // in 'um'. Adds '-1' when arr[i] == 0
    for (int i = 0; i < n; i++) {
        curr_sum += (arr[i] == 0) ? -1 : arr[i];
        um[curr_sum]++;
    }
 
    int count = 0;
    // traverse the hash table 'um'
    for (auto itr = um.begin(); itr != um.end(); itr++) {
 
        // If there are more than one prefix subarrays
        // with a particular sum
        if (itr->second > 1)
            count
                += ((itr->second * (itr->second - 1)) / 2);
    }
 
    // add the subarrays starting from 1st element and
    // have equal number  of 1's and 0's
    if (um.find(0) != um.end())
        count += um[0];
 
    // required count of subarrays
    return count;
}
int countSubarray(int arr[],int n){
    map<int,int> mp;
    int sum=0;
    mp[sum]++;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0){
            sum -= 1; 
        }
        else{
            sum+=1;
        }

        if(mp.find(sum) != mp.end())
        {
            count += mp[sum];
            mp[sum]++;
        }
        else{
            mp[sum]=1;
        }
    }
    return count;
}
 
// Driver program to test above
int main()
{
    int arr[] = { 1, 0, 0, 1, 1, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count = "
         << countSubarray(arr, n);
    return 0;
}
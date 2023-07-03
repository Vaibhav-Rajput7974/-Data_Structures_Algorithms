#include <iostream>
#include <vector>
using namespace std;
 
int gcd(int num1, int num2)
{
    if (num2 == 0)
        return num1;
    return gcd(num2, num1 % num2);
}
 
int lcm_of_array(vector<int> arr)
{
    int lcm = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        int num1 = lcm;
        int num2 = arr[i];
        int gcd_val = gcd(num1, num2);
        lcm = (lcm * arr[i]) / gcd_val;
    }
    return lcm;
}
 
int main()
{
    vector<int> arr1 = { 1, 2, 8, 3 };
    vector<int> arr2 = { 2, 7, 3, 9, 4 };
    cout << lcm_of_array(arr1) << endl; // Output: 24
    cout << lcm_of_array(arr2) << endl; // Output: 252
    return 0;
}



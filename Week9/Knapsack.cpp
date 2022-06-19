/*Given a knapsack of maximum capacity w. N items are provided, each having its own value and weight. You have to Design an algorithm and implement it using a 
program to find the list of the selected items such that the final selected content has weight w and has maximum value. You can take fractions of items,i.e. 
the items can be broken into smaller pieces so that you have to carry only a fraction x of item i, where 0 fix, 1.*/

#include <bits/stdc++.h>
using namespace std;
struct Item {
    int value, weight;
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, vector<Item> &arr, int n)
{
    sort(arr.begin(), arr.end(), cmp);

 
    double finalvalue = 0.0; 
    for (int i = 0; i < n; i++) {
 
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }
 
        else {
            finalvalue
                += arr[i].value
                   * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
 
int main()
{
    int n, W, val;
    cin>>n;
    vector<Item> arr(n);
    for(int i=0 ; i<n ; i++){
        cin>>val;
        arr[i].weight = val;
    }
    for(int i=0 ; i<n ; i++) {
        cin>>val;
        arr[i].value = val;
    }
    cin>>W;
    cout << "Maximum value = "
         << fractionalKnapsack(W, arr, n);
    return 0;
}

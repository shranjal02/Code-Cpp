#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeLap(vector<vector<int>> & arr, int n){
    sort(arr.begin(), arr.end());

    vector<vector<int>> merge;

    for(int i=0; i<n; i++){
        if(merge.empty() || merge.back()[1] < arr[i][0]){
            vector<int> v = {arr[i][0], arr[i][1]};
            merge.push_back(v);
        }
        else{
            merge.back()[1] = max(merge.back()[1], arr[i][1]);
        }

    }

    return merge;
}


int main(){
    vector<vector<int>> arr = {{1,2},{2,3},{4,5},{7,8}};
    vector<vector<int>> merge = mergeLap(arr, arr.size());
    for(int i=0; i<merge.size(); i++){
        for(int j=0; j<merge[0].size(); j++){
            cout << merge[i][j] << " ";
        }cout << endl;
    }
    return 0;
}
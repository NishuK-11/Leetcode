#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> MinNoOfJumps(vector<int> coins,int amount){
    int n = coins.size();
    sort(coins.begin(),coins.end(),greater<int>());//sort descending
    vector<pair<int,int>>pairs;
    
    for(int i =0;i<n;i++){
        if(coins[i]<=amount){
            int cnt = amount/coins[i];
            pairs.push_back(make_pair(coins[i],cnt));
            amount = amount-cnt*coins[i];
        }
    }
    if(amount==0){
        return pairs;
    }else{
        return {};
    }
}

int main(){
    vector <int>coins = {1,2,10,5};
    int amount = 39;
    vector<pair<int,int>>result = MinNoOfJumps(coins,amount);
    if(!result.empty()){
        cout<<"Coin usage to form amount:\n";
        for(auto p:result){
            cout<<"Coin:"<<p.first<<"->Count:"<<p.second<<endl;

        }
    }else{
        cout<<"Cannot form amount with given coins.\n";
    }
    return 0;
}
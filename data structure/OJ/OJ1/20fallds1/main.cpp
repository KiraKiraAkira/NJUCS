#include <iostream>
#include <vector>
using namespace std;
vector<int> result;
void luck(int n){
    int count=0;
    int hash[100000];
    for(int i=0;i<100000;i++){
        hash[i] = 1;
    }
    for(int i=2;i<100000;i++){
        if(hash[i]==1){
            count++;
            result.push_back(i);
            int step=0;
            for(int j=i+1;j<100000;j++){
                if(hash[j]==1){
                    step++;
                }
                if(step==i){
                    hash[j]=0;
                    step=0;
                }
            }
            if(count==n) {
                return ;
            }
        }
    }
}
int main() {
    vector<int> nums;
    int x;
    int max=-1;
    while (true){
        cin>>x;
        if(x==0) break;
        nums.push_back(x);
        if(x>max){
            max=x;
        }
        //cout<<luck(x)<<endl;
    }
    luck(max);
    for(int i=0;i<nums.size();i++) {
        cout << result[nums[i]-1] << endl;
    }
    return 0;
}

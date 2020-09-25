#include <iostream>
using namespace std;
int main() {
    //std::cout << "Hello, World!" << std::endl;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        int index,id;
        cin>>index>>id;
        a[id]=index;
    }
    int s=0;
    for(int i=0;i<n;i++){
        cout<<a[s]<<" ";
        s=a[s];
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n;
int arr[100100];
int t[400400]; //4*N even though 2*N-1 nodes are there

// 1+2+4+.... 2^(ceil(log(n)))+1   more than 2*n-1

void build(int index, int l, int r){
    if(l==r){ //means leaf node
        t[index]=arr[l]; //assigning leaf node value
        return;
    }

    //otherwise build left tree and build right tree
    int mid = (l+r)/2;
    build(index*2, l, mid);
    build(index*2+1 , mid+1, r);
    t[index]= t[2*index]+t[2*index+1];
}

void update(int index,int l, int r, int pos, int val){
    if(pos<l || pos>r){
        return;
    }
    if(l==r){
        t[index]=val;
        arr[l]=val;
    }
    int mid = (l+r)/2;
    update(index*2, l, mid, pos, val);
    update(index*2+1, mid+1, r, pos, val);
    t[index]= t[2*index]+t[2*index+1]; //merging logic
}

int query(int index, int l, int r, int lq, int rq){
    if(l>rq|| lq>r) {
        return 0;
    }
    if(lq<=l && r<=rq){
        //lq<=l<=r<=rq
        return t[index];
    }
    int mid = (l+r)/2;
    return query(index*2, l, mid, lq, rq)+ query(index*2+1, mid+1, r,lq,rq);
}


void shiv_prime94(){
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(1,0,n-1);
    // int q;
    // cin>>q;
    for(int i=0;i<q;i++){
        // int ch;
        // cin>>ch;
        // if(ch==1){
        //     int x,v;
        //     cin>>x>>v;
        //     update(1,0,n-1,x,v);
        // }else{
            int l, r;
            cin>>l>>r;
            cout<<query(1,0, n-1,--l,--r)<<endl;
        // }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    // bcin>>test;
    while(test--)
    {
        shiv_prime94();
    }
    return 0;
}

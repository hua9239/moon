#include<iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int n, x, len, a[50][50] = {0}, time = 0;
    cin>>n;

    x = n/2+1;
    len = n + (n-x)*2-1+x + n*2 - 1;

    for(int i = 0 ; i < n ; i++){
        a[x-1][i] = 1;
        time++;
    }

    for(int i = 1 ; i <= n-x ; i++){
        a[x+i-1][time] = 1;
        time++;
    }
    
    for(int i = n-1 ; i >=0 ; i--){
        a[i+1-1][time-1] = 1;
        time++;
    }

    for(int i = 0 ; i < n*2-1 ; i++){
        a[0][time-1] = 1;
        time++;
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < len ; j++){
            if(a[i][j] == 1)
                cout<<'*';
            else
                cout<<u8"\u2004";
                //cout<<' ';
            //cout<<a[i][j];
        }
        cout<<endl;
    }
    //cout<<len;
    return 0;
}
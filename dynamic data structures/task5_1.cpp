#include<iostream>
#include<queue>
using namespace std;

const int n = 12;

int main(){
    setlocale(LC_ALL,"rus");
    queue <int> q;
    
    cout << "Р’РІРµРґРёС‚Рµ " << n << " С‡РёСЃРµР»: " << endl;
    
    int max = -999999999;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > max) max = a;
        q.push(a);
    }
    
    int k = 0;
    for (int i = 0; i < n; i++) {
        int b = q.front();
        if (b == max) k ++;
    }
    
    queue <int> q2;
    int l = 0;
    while (!q.empty()){
        int a;
        a = q.front();
        if ((a == max && l == 0) or (a == max && l == k - 1)){
            l ++;
        }
        else q2.push(a);
        q.pop();
    }
    cout<<endl;
    
    
    while (!q2.empty()){
        int a;
        a = q2.front();
        cout<<a<<" ";
        q2.pop();
    }
}

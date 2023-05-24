#include<iostream>
#include<stack>
using namespace std;

const int n = 10;

int main(){
    setlocale(LC_ALL,"rus");
    stack <int> q;
    
    cout << "Р’РІРµРґРёС‚Рµ " << n << " С‡РёСЃРµР»: " << endl;
    
    int max = -999999999;
    int min = 999999999;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > max) max = a;
        if (a < min) min = a;
        q.push(a);
    }
    
    stack <int> q2;
    while (!q.empty()){
        int a;
        a = q.top();
        q2.push(a);
        if (a == max) q2.push(min);
        q.pop();
    }
    cout<<endl;
    
    
    while (!q2.empty()){
        int a;
        a = q2.top();
        cout<<a<<" ";
        q2.pop();
    }
}

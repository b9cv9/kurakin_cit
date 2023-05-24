#include<iostream>
#include<queue>
using namespace std;

const int n = 20;

int main(){
    setlocale(LC_ALL,"rus");
    queue <int> q;
    queue <int> q1;
    queue <int> q2;
    cout << "Р’РІРµРґРёС‚Рµ " << n << " С‡РёСЃРµР»: " << endl;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
        q2.push(a);
    }
    
    q1.push(q.front());
    q.pop();
    while (!q.empty()){
        q2 = q1;
        int a;
        a = q.front();
        int kolvo = 0;
        while (!q2.empty()){
            int b = q2.front();
            if (a == b) kolvo ++;
            q2.pop();
        }
        if (kolvo == 0) q1.push(a);
        q.pop();
    }
    cout<<endl;
    
    
    
    while (!q1.empty()){
        int a;
        a = q1.front();
        cout<<a<<" ";
        q1.pop();
    }
}

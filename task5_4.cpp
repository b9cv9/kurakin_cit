#include<iostream>
#include<stack>
using namespace std;

const int n = 9;

int main(){
    setlocale(LC_ALL,"rus");
    stack <int> q;
    int ch;
    cout << "Р’РІРµРґРёС‚Рµ " << n << " С‡РёСЃРµР»: " << endl;
    int kolvo_nechet = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
        if (a % 2 == 1) kolvo_nechet ++;
    }
    cout << endl;
    cout << "Р§РёСЃР»Рѕ, РєРѕС‚РѕСЂРѕРµ РЅР°РґРѕ РІСЃС‚Р°РІРёС‚СЊ: ";
    cin >> ch;
    
    
    stack <int> q2;
    int k = 1;
    while (!q.empty()){
        int a;
        a = q.top();
        if (a % 2 == 1 && k == kolvo_nechet){
            q2.push(ch);
        }
        else if (a % 2 == 1) k ++;
        q.pop();
        q2.push(a);
    }
    cout<<endl;
    
    
    
    while (!q2.empty()){
        int a;
        a = q2.top();
        cout<<a<<" ";
        q2.pop();
    }
}

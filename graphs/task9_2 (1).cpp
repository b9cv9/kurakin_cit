#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print(vector<set<int>> st){
    for (int i = 0; i < st.size(); i++){
        auto it = st[i].begin();
        cout<<i<<": ";
        for (it; it!=st[i].end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    vector<set<int>> graf_set = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 4, 3, 5},
        {1, 4, 5, 2},
        {2, 3},
        {3, 2}
    };

    int a, b;
    print(graf_set);
    cout<<"Введите вершину A и B"<<endl;
    cin>>a>>b;
    cout<<endl;
    graf_set[a].insert(b);
    graf_set[b].insert(a);
    print(graf_set);
}
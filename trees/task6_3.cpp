#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
 
 
struct tree {
   int inf;
   tree *right;
   tree * left ;
};
  
tree *node(int x){
   tree *n = new tree;
   n ->inf = x;
   n ->left = n ->right = NULL;
   return n;
}
  
  
void create(tree *&tr, int n){
    int x;
    if (n > 0){
        cout<<"x: ";
        cin >> x;
        tr = node(x);
        int nl = n/2;
        int nr = n  - nl  -  1;
        create(tr ->left, nl);
        create(tr ->right,nr);
    }
}


int righth(tree *tr){
    int k = 0;
    tree *x = tr;
    while (x){
        k++;
        x = x ->right;
    }
    return k  -  1;
}

int lefth(tree *tr){
    int k = 0;
    tree *x = tr;
    while (x){
        k++;
        x = x ->left;
    }
    return k  -  1;
}
  
int list_count(tree* tr, int &n){
    if (!tr)
        return 0;
    if (!tr->left && !tr->right)
        return n += tr->inf;
    return list_count(tr->left, n) + list_count(tr->right, n);
}



   
void print(tree *tr, int k){
    if (! tr ) cout << "Empty tree\n";

    else{
        queue<tree*> cur, next;
        tree *r = tr;
        cur.push(r);
        int j = 0;
        while (cur.size()){
            if (j == 0) {
                for (int i = 0; i < (int)pow(2.0, k)  -  1; i++)
                    cout << ' ';
            }

            tree *buf = cur.front() ;
            cur.pop();
            j++;
            if (buf){
                cout << buf->inf;
                next.push(buf ->left);
                next.push(buf ->right);
                for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
                    cout << ' ';
            }

            if (!buf){
                for (int i = 0; i < (int)pow(2.0 , k + 1)  - 1; i++)
                    cout << ' ';
                cout << ' ';
            }
            if(cur.empty()){
                cout << endl;
                swap(cur, next);
                j = 0;
                k--;
            }
        }
    }
}
    

    void schet_summ(tree *tr, int &n){
    if(tr){
        schet_summ ( tr->left, n);
        if (!tr->left && !tr->right) n += tr->inf;
        schet_summ ( tr->right, n);
    }
}

int main(){
    tree *tr = NULL;
    int n, x;
    n=6;
    create(tr , n);
    int k = int (log((float)n)/log((float)2.0));
    print(tr, k);

    cout<<endl<<endl;
    int net = 0;
 
    schet_summ(tr, net);
    cout << net << endl;
}

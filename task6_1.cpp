#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

tree* newtree(int key)
{
	tree* temp = new tree;
	temp->data = key;
	temp->left = temp->right = NULL;
	return (temp);
}

void print_tree(tree* tr){
	if (!tr)
		return;

	queue<tree*> q;
	q.push(tr);
	while (!q.empty()) {
		tree* temp = q.front();
		cout << temp->data << " ";
		q.pop();

		if (temp->left != NULL) {
			q.push(temp->left);
		}

		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}
}

tree * minimum(tree *tr)
{
	if (!tr->left->left) return tr;
	return minimum(tr->left);
}



void delete_node(tree** tr, int num, tree* parent) //процедура удаления элемента
{
	if (!(*tr)) return; //если дерево пусто, выход из процедуры
	
	if (num < (*tr)->data)
		delete_node(&((*tr)->left), num, *tr);
	else if (num >(*tr)->data)
		delete_node(&((*tr)->right), num, *tr);
	else {
		
		if (!(*tr)->left && !(*tr)->right) {//Если детей у удаляемого узла нет, то перед нами самый простой случай - листовой узел.
			
			if (parent) {//Родителю данного узла надо сообщить о том, что потомка у него теперь нет 
				
				if (parent->left) {
					
					if (parent->left->data == (*tr)->data) { //Если удаляется левый потомок
						
						parent->left = NULL;
					}
				}
				if (parent->right) {
					
					if (parent->right->data == (*tr)->data) { //Если удаляется правый потомок
						
						parent->right = NULL;
					}
				}
			}
			free(*tr); // Освобождаем память
			*tr = NULL;
		}
		else if (!(*tr)->left || !(*tr)->right) { // Если у удаляемой вершины есть хотя бы один потомок
			
			tree* nodeToRemove = NULL;
			if ((*tr)->left) { //Находим того самого единственного потомка удаляемой вершины
				
				nodeToRemove = (*tr)->left;
			}
			else {
				
				nodeToRemove = (*tr)->right;
			}
			//Скопировать все данные из единственного потомка удаляемой вершины
			(*tr)->left = nodeToRemove->left;
			(*tr)->right = nodeToRemove->right;
			(*tr)->data = nodeToRemove->data;
			//Освободить память, выделенную ранее для данного потомка
			free(nodeToRemove);
		}
		else { //Если у удаляемой вершины есть оба потомка, то согласно алгоритму необходимо найти наименьший элемент в правом поддереве удаляемого элемента
			
			if (!(*tr)->right->left) { //Если у правого поддерева нет левых потомков, то это означает, что у всех потомков значение ключа больше,
				//а значит надо просто скопировать значения из правого потомка в удаляемый элемент
				(*tr)->data = (*tr)->right->data; // Скопировать значение из правого потомка
				tree* rightRIghtChild = (*tr)->right->right;
				free((*tr)->right); // Освбодить память, выделенную для правого потомка
				(*tr)->right = rightRIghtChild;
			}
			else {
				
				tree* minNodeParent = minimum((*tr)->right); //Поиск наименьшего элемента в правом поддереве (он обязательно найдётся, случай когда его нет был разобран выше)
				(*tr)->data = minNodeParent->left->data; //Скопировать значение из наименьшего жлемента в правом поддереве в удаляемый элемент
				free(minNodeParent->left);
				minNodeParent->left = NULL;
			}
		}
	}
}



tree* deleteEven(tree* tree){
	if (!tree) {
		return NULL;
	}
	
	tree->left = deleteEven(tree->left);
	tree->right = deleteEven(tree->right);
	
	if (tree->data % 2 != 0) delete_node(&tree, tree->data, NULL);
	
	return tree;
}


int main()
{
	struct tree* tr = newtree(1);
	tr->left = newtree(2);
	tr->left->left = newtree(8);
	tr->left->right = newtree(10);
	tr->right = newtree(7);
	tr->right->left = newtree(12);
	tr->right->right = newtree(5);
	tr->right->right->right = newtree(4);

    print_tree(tr);
    cout<<endl;

	tree *tr1 = deleteEven(tr);

	print_tree(tr1);
}
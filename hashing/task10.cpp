#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;



struct date {//дата
	int dd, mm, yy;
};


struct people {//данные о человеке
	string Surname; //фамилия
	date DateOfBirth; //дата рождения
	int Salary; //зарплата
	int Staj;
	string Dolj;
	int hash=NULL;
};


date Str_to_Date(string str) {//из строки в дату
	date x;
	string temp = str.substr(0, 2);//день
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);//месяц
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);//год
	x.yy = atoi(temp.c_str());
	return x;
}

vector<people> inFile() {//ввод из файла
	ifstream in("input.txt");
	if (in.is_open()) {
		cout << "otkrilsya" << endl;
		vector<people> x;
		people temp;
		while (!in.eof()) {
			in >> temp.Surname;//фамилия
			string tmp;//дата рождения
			in >> tmp;
			temp.DateOfBirth = Str_to_Date(tmp);
			in >> temp.Salary;//зарплата
			in >> temp.Staj;
			in >> temp.Dolj;
			x.push_back(temp);
		}
		return x;
	}
	else {
		cout << "ne otkrilsya" << endl;
	}
}

void oglav() {
	cout << "familiy" << "        ";//по левому краю, 10 позиций для фамилии
	cout << "Data           ";
	cout << "Zarplata  ";//запрлата
	cout << "Staj  ";//стаж
	cout << "Doljnost       ";//должность
	cout << "Hash  ";
	cout << "num"<<endl;
}

void print(people x) {//вывод в файл
	cout << setw(13) << left << x.Surname << "  ";//по левому краю, 10 позиций для фамилии
	if (x.DateOfBirth.dd < 10) cout << left << "0" << x.DateOfBirth.dd << ".";//добавляем 0
	else cout << left << x.DateOfBirth.dd << ".";
	if (x.DateOfBirth.mm < 10) cout << "0" << x.DateOfBirth.mm << ".";
	else cout << x.DateOfBirth.mm << ".";
    cout << x.DateOfBirth.yy << "     ";//на год 6 позиций
	cout << x.Salary << "     ";//запрлата
	cout << x.Staj << "     ";//стаж
	cout << x.Dolj;//должность
	cout<<"       "<<x.hash;
}

int give_hash(int perem){
	return perem%9;
}

void print_hash(vector<people>& mass){
	for (int i = 0; i < mass.size(); i++) {
		mass[i].hash=give_hash(mass[i].Staj);
	}
}

void find(int hash0, vector<people> mass){
	for (auto p : mass){
		if (p.hash==hash0){
			print(p);
			cout << endl;
		}
	}
}

void delete_people(int hash0, vector<people> &mass){
	int k;
	for (auto p : mass){
		if (p.hash==hash0){
			auto it = mass.begin();
    		advance(it, k);
    		mass.erase(it);
		}
		k++;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	vector<people> x;
	x = inFile();
	oglav();
	print_hash(x);
	int k;
	for (people item : x) {
		print(item);
		cout<<"    "<<k<<endl;
		k++;
	}

	cout<<endl<<endl;
	find(6, x);
	cout<<endl<<endl<<endl;
	delete_people(6, x);

	k=0;
	oglav();
	for (people item : x) {
		print(item);
		cout<<"    "<<k<<endl;
		k++;
	}
}
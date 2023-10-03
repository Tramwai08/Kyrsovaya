#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>
using namespace std;
struct Dela{
	string name;
	string prioritet;
	string data;
	string time;
	string txt;
};
void add(Dela dels) {
		cout << "\nВведите название дела ";
		cin.ignore();
		getline(cin, dels.name);
		cout << "\nВведите приоритет дела ";
		cin.ignore();
		getline(cin, dels.prioritet);
		cout << "\nВведите дату ";
		getline(cin, dels.data);
		cout << "\nВведите время ";
		getline(cin, dels.time);
		cout << "\nВведите описание к делу\n";
		getline(cin, dels.txt);
		cin.ignore();
		ofstream file("./spisok/" + dels.name + ".txt");
		if (file) {
			file << "Название: " << dels.name << endl;
			file << "Приоритет: " << dels.prioritet << endl;
			file << "Дата: " << dels.data << endl;
			file << "Время: " << dels.time << endl;
			file << "Описание: \n" << dels.txt << endl;
			file << "*************************************************************************************************************" << endl;
			file.close();
			cout << "Дело было успешно добавлена и сохранена в список ";
		}
		else cout << "Ошибка файла ";
}
void del(Dela dels) {
	string name2;
	cout << "Введите название дела которое нужно удалить ";
	cin.ignore();
	getline(cin, name2);
	if (remove(("./spisok/" + name2 + ".txt").c_str()) != 0) {
		cout << "Ошибка при удалении дела" << endl;
	}
	else cout << "Дело успешно удалено" << endl;
	
}
void red(Dela dels) {
	string name3;
	
	cout << "Введите название дела для редактирования ";
	cin >> name3;
	ifstream file1("./spisok/" + name3 + ".txt");
	if (!file1) {
		cout << "Файл не найден ";
		exit(0);
	}
	cout << "\nВведите название дела ";
	cin.ignore();
	getline(cin, dels.name);
	cout << "\nВведите приоритет дела ";
	cin.ignore();
	getline(cin, dels.prioritet);
	cout << "\nВведите дату ";
	getline(cin, dels.data);
	cout << "\nВведите время ";
	getline(cin, dels.time);
	cout << "\nВведите описание к делу\n";
	getline(cin, dels.txt);
	cin.ignore();
	ofstream file("./spisok/" + name3 + ".txt");
	if (file) {
		file << "Название: " << dels.name << endl;
		file << "Приоритет: " << dels.prioritet << endl;
		file << "Дата: " << dels.data << endl;
		file << "Время: " << dels.time << endl;
		file << "Описание: \n" << dels.txt << endl;
		file << "*************************************************************************************************************" << endl;
		file.close();
		cout << "Дело было успешно отредактировано и сохранена в список ";
	}
	else cout << "Ошибка файла ";
}
void poisk(Dela dels) {
	
}
int main(){
	setlocale(LC_ALL, "RUS");
	Dela dels;
	int vib;
	cout << "\t\t\t\t\tСписок ваших дел\nВыберите действие:\n[1]Добавить дело\n[2]Удалить \n[3]Редактировать \n[4]Поиск \n[5]Вывод дела на экран\nВаш выбор ";
	cin >> vib;
	switch (vib) {
	case 1: { 
	add(dels);
	break;
	}
	case 2: {
	del(dels);
	break;
	}
	case 3: {
		red(dels);
		break;
	}
	case 4: {
		poisk(dels);
		break;
	}
		/*case 5:*/
	}
}
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
		cout << "\n������� �������� ���� ";
		cin.ignore();
		getline(cin, dels.name);
		cout << "\n������� ��������� ���� ";
		cin.ignore();
		getline(cin, dels.prioritet);
		cout << "\n������� ���� ";
		getline(cin, dels.data);
		cout << "\n������� ����� ";
		getline(cin, dels.time);
		cout << "\n������� �������� � ����\n";
		getline(cin, dels.txt);
		cin.ignore();
		ofstream file("./spisok/" + dels.name + ".txt");
		if (file) {
			file << "��������: " << dels.name << endl;
			file << "���������: " << dels.prioritet << endl;
			file << "����: " << dels.data << endl;
			file << "�����: " << dels.time << endl;
			file << "��������: \n" << dels.txt << endl;
			file << "*************************************************************************************************************" << endl;
			file.close();
			cout << "���� ���� ������� ��������� � ��������� � ������ ";
		}
		else cout << "������ ����� ";
}
void del(Dela dels) {
	string name2;
	cout << "������� �������� ���� ������� ����� ������� ";
	cin.ignore();
	getline(cin, name2);
	if (remove(("./spisok/" + name2 + ".txt").c_str()) != 0) {
		cout << "������ ��� �������� ����" << endl;
	}
	else cout << "���� ������� �������" << endl;
	
}
void red(Dela dels) {
	string name3;
	
	cout << "������� �������� ���� ��� �������������� ";
	cin >> name3;
	ifstream file1("./spisok/" + name3 + ".txt");
	if (!file1) {
		cout << "���� �� ������ ";
		exit(0);
	}
	cout << "\n������� �������� ���� ";
	cin.ignore();
	getline(cin, dels.name);
	cout << "\n������� ��������� ���� ";
	cin.ignore();
	getline(cin, dels.prioritet);
	cout << "\n������� ���� ";
	getline(cin, dels.data);
	cout << "\n������� ����� ";
	getline(cin, dels.time);
	cout << "\n������� �������� � ����\n";
	getline(cin, dels.txt);
	cin.ignore();
	ofstream file("./spisok/" + name3 + ".txt");
	if (file) {
		file << "��������: " << dels.name << endl;
		file << "���������: " << dels.prioritet << endl;
		file << "����: " << dels.data << endl;
		file << "�����: " << dels.time << endl;
		file << "��������: \n" << dels.txt << endl;
		file << "*************************************************************************************************************" << endl;
		file.close();
		cout << "���� ���� ������� ��������������� � ��������� � ������ ";
	}
	else cout << "������ ����� ";
}
void poisk(Dela dels) {
	
}
int main(){
	setlocale(LC_ALL, "RUS");
	Dela dels;
	int vib;
	cout << "\t\t\t\t\t������ ����� ���\n�������� ��������:\n[1]�������� ����\n[2]������� \n[3]������������� \n[4]����� \n[5]����� ���� �� �����\n��� ����� ";
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
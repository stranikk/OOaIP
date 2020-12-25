#include "Client.h"
#include <iostream>
#include <locale.h>
#include <windows.h>
#include "pch.h"

Client::Client(MyDB* _db)
{
	db = _db;
}

void Client::startSession()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	string delimiter = "$$";
	int cmd, count;
	double price;
	string name, product_name, descr, password;
	string query;
	do
	{
		print_help();
		cout << "**************************************************" << endl;
		cout << "������� �������: ";                  // ������� �������
		cin >> cmd;
		switch (cmd)
		{
		case 0:
			query = "";
			break;
		case 1:
			cout << "�����: ����������� ������ ������������..." << endl;
			cout << "������� ����� ������������: ";
			cin.ignore();
			getline(cin, name);
			cout << "������� ������: ";
			getline(cin, password);
			cout << "���� ������������ ����� �������� ��������������� ������� 1, ����� - 0: ";
			cin >> count;
			query = "1" + delimiter + name + delimiter + password + delimiter + to_string(count) + delimiter;
			break;
		case 2:
			cout << "�����: ���������� ������ ������..." << endl;
			cout << "������� �������� ������: ";
			cin.ignore();
			getline(cin, product_name);
			cout << "������� ��������� ������: ";
			cin >> price;
			cout << "������� ���������� ������: ";
			cin >> count;
			cout << "������� ������� �������� ������: ";
			cin.ignore();
			getline(cin, descr);
			query = "2" + delimiter + product_name + delimiter + to_string(price) + delimiter + to_string(count) + delimiter + descr + delimiter;
			break;
		case 3:
			cout << "�����: ���������� ���������� � ������..." << endl;
			cout << "������� �������� ������: ";
			cin.ignore();
			getline(cin, product_name);
			cout << "������� ����� ��������� ������: ";
			cin >> price;
			cout << "������� ����� ���������� ������: ";
			cin >> count;
			cout << "������� ����� ������� �������� ������: ";
			cin.ignore();
			getline(cin, descr);
			query = "3" + delimiter + product_name + delimiter + to_string(price) + delimiter + to_string(count) + delimiter + descr + delimiter;
			break;
		case 4:
			cout << "�����: ���� ������������..." << endl;
			cout << "������� ��� �����: ";
			cin.ignore();
			getline(cin, name);
			cout << "������� ������: ";
			getline(cin, password);
			query = "4" + delimiter + name + delimiter + password + delimiter;
			break;
		case 5:
			cout << "�����: �������� ���� ������� (������� ������)..." << endl;
			query = "5" + delimiter;
			break;
		case 6:
			cout << "�����: �������� ��������� ���������� � ������..." << endl;
			cout << "������� �������� ������: ";
			cin.ignore();
			getline(cin, product_name);
			query = "6" + delimiter + product_name + delimiter;
			break;
		case 7:
			cout << "�����: �������� ������..." << endl;
			query = "7" + delimiter;
			break;
		case 8:
			cout << "�����: ���������� ������ � �����..." << endl;
			cout << "������� �������� ������: ";
			cin.ignore();
			getline(cin, product_name);
			cout << "������� ����������: ";
			cin >> count;
			query = "8" + delimiter + product_name + delimiter + to_string(count) + delimiter;
			break;
		case 9:
			cout << "�����: �������� ������..." << endl;
			query = "9" + delimiter;
			break;
		case 10:
			cout << "�����: ������ ������..." << endl;
			cout << "������� ������������ ���������� �����: ";
			cin >> price;
			query = "10" + delimiter + to_string(price) + delimiter;
			break;
		default:                               // �������� �������
			cout << "������������ �������. ���������� �����." << endl;
			query = "";
		}
		if (query != "")
		{
			cout << "***********************" << endl;
			cout << "������ �������: " << endl << query << endl;
			cout << "***********************" << endl;
			cout << "����� �������: " << endl << db->runQuery(query) << endl;
			cout << "***********************" << endl;
		}
		cout << "**************************************************" << endl;
	} while (cin && (cmd != 0));
}

void Client::print_help()
{
	cout << endl << "�������:" << endl;
	cout << " 1: ����������� ������ ������������" << endl;
	cout << " 2: �������� ����� �����" << endl;
	cout << " 3: �������� ���������� � ������" << endl;
	cout << " 4: ���� ������������" << endl;
	cout << " 5: �������� ���� ������� (������� ������)" << endl;
	cout << " 6: �������� ��������� ���������� � ������" << endl;
	cout << " 7: �������� ������" << endl;
	cout << " 8: ���������� ������ � �����" << endl;
	cout << " 9: �������� ������" << endl;
	cout << " 10: ������ ������" << endl;
	cout << " 0: �����" << endl;
	cout << endl;
}

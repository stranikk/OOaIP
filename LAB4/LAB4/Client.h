#pragma once
#include "Server.h"
#include "pch.h"
class Client //����� ��� ���������� �����
{
public:
	Client(MyDB* _db); // �����������, ����������� ���� ������
	void startSession(); // ����� ����� ���������� �������������
private:
	void print_help(); // ������� � ��������� ��� ������������
	MyDB* db; // ���� ������, � ������� ����� ���������� ������
};

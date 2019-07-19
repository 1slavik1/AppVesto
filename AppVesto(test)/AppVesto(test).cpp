// AppVesto(test).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <C:\libs\json.hpp\include\nlohmann\json.hpp>
using json = nlohmann::json;
using namespace std;
int main()
{	
	string s,ver_temp;
	string line;
	string word = "Flutter";
	ifstream in("D:\\file.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		bool flag = false;
		while (getline(in, line))
		{
			size_t found = line.find(word);
			if (found != string::npos)
			{
				//строка в массив
				char *str = new char[line.size() + 1];
				copy(line.begin(), line.end(), str);
				str[line.size()] = '\0';
				
				for (int i = 0; i < line.size(); i++)
				{
					int c = i + 2;
					if ((str[i] == '0' || str[i] == '1' || str[i] =='2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i]== '9')
						&& (str[i + 1] == '.') 
						&& (str[c] == '0' || str[c] == '1' || str[c] == '2' || str[c] == '3' || str[c] == '4' || str[c] == '5' || str[c] == '6' || str[c] == '7' || str[c] == '8' || str[c] == '9'))
					{
						//cout << line << endl;
						//cout << "version of flutter is " <<str[i] << str[i + 1] << str[i + 2];
						
						 ver_temp = str[i];
						 ver_temp += str[i + 1];
						 ver_temp += str[c];
						 cout << "version of flutter is " << ver_temp << endl;
						flag = true;
						break;
					}
				}
			}
			if (flag) break;

			//cout<< endl << line << endl;
		}

		
		
		
	}
	in.close();     // закрываем файл

	json j;
	j["Version of flutter"] = ver_temp;

	s = j.dump();
	ofstream out;
	out.open("D:\\source.json"); // окрываем файл для записи
	if (out.is_open())
	{
		out << s << std::endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

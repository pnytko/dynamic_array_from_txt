#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Ustalenie œcie¿ki roboczej
string Path = ".\\2022-04-02_05-42-49_MAP_o.txt";

//Funkcja zwracaj¹ca iloœæ wierszy, przydatna do generowania dynamicznej tablicy
int ReturnRowNumber(string Path)
{
	fstream ThrowCenters;
	ThrowCenters.open(Path, ios::in);
	int Counter = 0;
	string SimpleLine;
	while (!ThrowCenters.eof())
	{
		getline(ThrowCenters, SimpleLine);
		Counter++;
	}
	ThrowCenters.close();

	return Counter;
}

int main()
{
	int temp = ReturnRowNumber(Path);
	string** Array;
	Array = new string*[temp];
	for (int i = 0; i < temp; i++)
	{
		Array[i] = new string[9];
	}

	fstream ThrowCenters;
	ThrowCenters.open(Path, ios::in);
	if (ThrowCenters.good())
	{
		cout << "Wczytuje plik." << endl<< "\n";
		int Row = 0;
		string SimpleLine;

		while (!ThrowCenters.eof())
		{
			getline(ThrowCenters, SimpleLine);
			string Delimiter = "\t";
			string LineWithDelim = SimpleLine + Delimiter;
			size_t Position = 0;
			string Token;
			int Column = 0;
			while ((Position = LineWithDelim.find(Delimiter)) != string::npos)
			{
				Token = LineWithDelim.substr(0, Position);
				Array[Row][Column] = Token;
				LineWithDelim.erase(0, Position + Delimiter.length());
				Column++;
			}
			Row++;
		}
		ThrowCenters.close();
	}


	//Wypisywanie wartoœci tablicy w podwójnej pêtli
	for (int k = 0; k < temp; k++)
	{
		for (int l = 0; l < 9; l++)
		{
			cout << Array[k][l] << " ";
		}
		cout << endl;
	}

	//string PobranaWartosc = Tablica[2134][3];
	//cout << PobranaWartosc;

	return 0;
}

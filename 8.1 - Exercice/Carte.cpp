#include <iostream>
#include <vector>
#include <fstream>
#include <string>


std::vector<std::vector<char> > map(20, std::vector<char>(20));

int main(){

	std::cout << "map informations : \n";
	std::cout << " = ground\n";
	std::cout << "€ = wall\n";
	std::cout << "* = player\n";

	char randNum = (rand() % 6) + 1;
	char randNum2 = (rand() % 7) + 7;

	std::ofstream outfile;
	outfile.open("Carte.txt");

	char wallSymbol = '°';
	char playerSymbol = '¦';

	for (int i = 0; i < 4; i++)
	{
		map[i + 2][1] = wallSymbol;
		map[i + 2][2] = wallSymbol;
		map[i + 2][3] = wallSymbol;
		map[i + 2][4] = wallSymbol;
		map[i + 2][5] = wallSymbol;
		map[i + 2][9] = wallSymbol;
		map[i + 2][10] = wallSymbol;
		map[i + 2][11] = wallSymbol;
		map[i + 2][12] = wallSymbol;
	}

	for (int i = 0; i < 6; i++)
	{
		map[i + 9][11] = wallSymbol;
		map[i + 9][12] = wallSymbol;
		map[i + 9][13] = wallSymbol;
	}

	int lastElement = map.size() - 1;

	for (int i = 0; i < map.size(); i++)
	{
		map[i][0] = wallSymbol;
		map[0][i] = wallSymbol;
		map[lastElement][i] = wallSymbol;
		map[i][lastElement] = wallSymbol;
	}

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (j == 19) {
				outfile << " . " << map[i][j] << "\n";
			}
			else
				outfile << " . " << map[i][j];
		}
		std::cout << "\n";
	}
	outfile.close();

	std::ifstream inFile;
	inFile.open("Carte.txt");
	
		for (int i = 0; i < map.size(); i++)
		{
			for (int j = 0; j < map[i].size(); j++)
			{
				for (std::string line; getline(inFile, line); ) {
					std::cout << line << "\n";
				}
			}
		}

	system("pause");
	inFile.close();

	return EXIT_SUCCESS;
}

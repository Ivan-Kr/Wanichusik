#include "Kiwii/DatoBased/Table.h"
#include <iostream>

int main(){
	Kiwii::Table<int>table;

	table._name_r("Table");
	table.set_table(5, 5);
	
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			table.table(i, j,rand()%i*j);
		}
	}

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			std::cout<<table.table(i, j)<<' ';
		}
		std::cout << '\n';
	}

	return 0;
}

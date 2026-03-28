#include <iostream>
#include "Sort.h"

using namespace std;

int main() {
	cout << "Bubble Sort crescator" << endl;
	Sort lista1(7, 10, 99);
	cout << "Lista initiala: "; lista1.Print();
	lista1.BubbleSort(true);
	cout << "Dupa sortare: "; lista1.Print();
	cout << "Elementul de la index 3: " << lista1.GetElementFromIndex(3) << endl << endl;

	cout << "Insert Sort descrescator" << endl;
	Sort lista2({ 52, 36, 44,14, 26 });
	cout << "Lista initiala: "; lista2.Print();
	lista2.InsertSort(false);
	cout << "Dupa sortare: "; lista2.Print();
	cout << "In total avem " << lista2.GetElementsCount() << " elemente" << endl << endl;

	cout << "Quick Sort crescator" << endl;
	int vector[5] = { 5,9,1,3,7 };
	Sort lista3(vector, 5);
	cout << "Lista inainte de sortare: "; lista3.Print();
	lista3.QuickSort(true);
	cout << " Dupa sortare: "; lista3.Print();
	cout << endl;

	cout << "Bubble Sort descrescator (mai multe elemente)" << endl;
	Sort lista4(6, 98, 45, 27, 81, 14, 57);
	cout << "Lista inainte de sortare: "; lista4.Print();
	lista4.BubbleSort();
	cout << "Dupa sortare: "; lista4.Print();
	cout << endl;

	cout << "Quick Sort crescator" << endl;
	Sort lista5("10, 42, 100, 9, 77");
	cout << "Inainte de sortare: "; lista5.Print();
	lista5.QuickSort(true);
	cout << "Dupa sortare: "; lista5.Print();
	cout << endl;

	return 0;
}
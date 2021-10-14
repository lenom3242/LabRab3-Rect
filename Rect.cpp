#include <iostream>
#include <ctime>
using namespace std;
class Rect
{
private:
	int dlina, shirina;
	static int number;
public:
	int getdlina(){return dlina;}
	int getshirina(){return shirina;}
	static int getnumber(){return number;}
	static void showinfo(Rect **newarr)
	{
		for (int i = 0; i < 9; i++)
			cout << newarr[i]->getdlina() << newarr[i]->getshirina() << endl;
	}
	Rect():dlina(1),shirina(1)
	{number++;}
	Rect(int newdlina, int newshirina) : dlina(newdlina), shirina(newshirina)
	{if(newdlina == newshirina)number++;}
};
int Rect::number = 0;
void main()
{
	srand(time(0));
	Rect** arr = new Rect*[10];
	for (int i = 0; i < 10; i++)
		arr[i] = new Rect(rand() % 3 + 1, rand() % 3 + 1);
	Rect::showinfo(arr);
	cout << Rect::getnumber();
	for (int i = 0; i < 9; i++)
		delete arr[i];
	delete[] arr;
}
//Rect* arr2 = (Rect*)malloc(sizeof(Rect) * 10);
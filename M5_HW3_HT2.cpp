#include <iostream>
#include "Windows.h"


class smart_array
{
private:
	int* arr;
	int* end;
	int fsize = 0;
	int lsize = 0;
	int destr_counter=0;

public:
	smart_array(int setfsize) :fsize{ setfsize }
	{
		arr = new int[fsize];
	}

	void add_element(int elem)
	{
		if (lsize < fsize)
		{
			arr[lsize] = elem;
			lsize++;
		}
		else
		{
			fsize = fsize * 2;
			int* new_arr = new int[fsize];
			for (int i = 0; i < lsize; i++) new_arr[i] = arr[i];


			new_arr[lsize] = elem;

			lsize = lsize + 1;

			delete[] arr;

			arr = new_arr;
		}
	};


	~smart_array()
	{
		//delete[] arr;
	};

	void print_arr()
	{
		std::cout << "Динамический массив: \n";
		for (int i = 0; i < fsize; i++)
		{
			if (i < lsize) std::cout << arr[i] << " ";
			else std::cout << "_ ";
		}
		std::cout << std::endl;
	}

	int get_element(int num)
	{
		return arr[num];
	}

	smart_array operator=(smart_array other) 
	{
		for (int i = 0; i < fsize; i++)
		{
			arr[i] = other.arr[i];
			lsize = other.lsize;
		}
		return 0;
	}
};



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int fsize = 5;
	int destr_counter = 0;

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.print_arr();

		smart_array new_array(2);
		new_array.add_element(45);
		new_array.add_element(34);
		new_array.print_arr();

		arr = new_array;

		arr.print_arr();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}


}


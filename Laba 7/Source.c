#include "arrays.h"


int main()
{
	int choice = 0;
	int (*task)(void) = NULL;
	choice = choice_task(choice);
	switch (choice)
	{
	case 1:
		task = task1;
		task1();
		break;
	case 2:
		task = task2;
		task2();
		break;
	case 3:
		task = end;
		end();
		break;
	}
}

#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

int end()
{
	return 0;
}

void output(char* string, int max_word, int length_longest)
{
	printf("\nMax word: ");
	for (int i = max_word; i < length_longest; i++)
		printf("%c", string[i]);
}

int choice_task(int choice)
{
	printf("1 - First Task, 2 - Second Task, 3 - Exit\n");
	printf("Your choice: ");
	while (scanf_s("%d", &choice) == 0 || choice > 3 || choice < 1 || getchar() != '\n')
	{
		printf("You need to write correct numbers\n");
		printf("Your choice: ");
		rewind(stdin);
	}
	return choice;
}

void input_string(char** string)
{
	char symbol;
	int i = 0;
	while ((symbol = getchar()) != '\n')
	{
		(*string)[i] = symbol;
		i++;
	}
	(*string) = realloc(*string, i * sizeof(char));
	(*string)[i] = '\0';
}

int len_string(char* string, int start)
{
	int length = 0;
	while (string[start] != ' ' && string[start] != '\0')
	{
		start++;
		length++;
	}
	return length;
}

int len_string_2(char* string, int start)
{
	int length = 0;
	while (string[start] != '\0')
	{
		start++;
		length++;
	}
	return length;
}

int max_len_word(char* string)
{
	int i = 0;
	int length_longest = 0;
	int max_word = 0;
	int end_of_longest_word = 0;
	while(string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			i++;
			continue;
		}
		if (len_string(string,i) > length_longest)
		{
			length_longest = len_string(string, i);
			max_word = i;
		}
		i += len_string(string, i);
	    end_of_longest_word = i;
	}	
	printf("Length of longest word - %d\n", length_longest);
	output(string, max_word, end_of_longest_word);
	return max_word;
}


int task1()
{
	int  max_word = 0, length_longest = 0;
	char* string = (char*)malloc(256);
	printf("Enter a string: ");
	input_string(&string);
	max_word = max_len_word(string);
}

int find_first_word(char** string2)
{
	int ind_of_start_of_first_word = 0;
	int ind_of_end_of_first_word = 0;
	while ((*string2)[ind_of_start_of_first_word] == ' ' && (*string2)[ind_of_start_of_first_word] != '\0')
	{
		ind_of_start_of_first_word++;
	}
	ind_of_end_of_first_word = ind_of_start_of_first_word;
	while ((*string2)[ind_of_end_of_first_word] != ' ' && (*string2)[ind_of_end_of_first_word] != '\0')
	{
		ind_of_end_of_first_word++;
	}
	int length = ind_of_end_of_first_word - ind_of_start_of_first_word;
	return length;
}

void delete_word(char* string1, char* string2, int length1, int length2)
{
	int length_of_first_word = find_first_word(&string2);
	for (int i = 0; i < length1; i++)
	{
		int j = 0;
		while (string1[i] == string2[j] && string1[i] != '\0' && string2[j] != ' ')
		{
			i++;
			j++;
		}
		if (j == length_of_first_word)
		{
			int k = i - length_of_first_word;
				while(string1[k + length_of_first_word] != '\0')
				{
					string1[k] = string1[k + length_of_first_word];
					k++;
				}
				string1 = realloc(string1, (length1 - length_of_first_word + 1) * sizeof(char));
				string1[k] = '\0';
				printf("\nNew string1: %s", string1);
				break;
		}
	}

}
int task2()
{ 
	char* string1 = (char*)malloc(256);
	char* string2 = (char*)malloc(256);
	printf("\nEnter string(S):");
	input_string(&string1);
	printf("Enter string(S0):");
	input_string(&string2);
	printf("string(S) - %s\nstring(S0) - %s\n", string1, string2);
	int length_of_string1 = 0, length_of_string2 = 0;
	length_of_string1 = len_string_2(string1, 0);
	length_of_string2 = len_string_2(string2, 0);
	delete_word(string1, string2, length_of_string1, length_of_string2);
}

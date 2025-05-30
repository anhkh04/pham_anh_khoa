#include "mylib.h"

int findSize(char* str)
{
	int cnt = 0;
	while (str[cnt] != 0)
	{
		cnt++;
	}

	return cnt;
}

char* findSubstr(char* str, char* substr)
{
	int i = 0;
	while (*(substr + i) != 0)
	{
		int j = 0;
		while ((*substr + i) != *(str + j))
		{
			j++;
		}
		i++;
	}
}

int countSpace(char* str)
{
	int i = 0, cnt = 0;
	while (str[i] != 0)
	{
		if (str[i] == ' ')
		{
			cnt++;
		}
		i++;
	}
	return cnt;
}

void uppercase(char* str)
{
	int size = findSize(str);

	for (int i = 0; i < size; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') 
		{
			str[i] -= 32;
		}
	}
}

int isWord(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return 1; 
	}
	else
	{
		return 0;
	}
}

int countWord(char* str)
{
	int cnt = 0;
	int size = findSize(str);

	for (int i = 0; i < size; i++)
	{
		if (isWord(str[i]) && !isWord(str[i - 1]))
		{
			cnt++;
		}
	}
	return cnt;
}

void upperFirstLetter(char* str)
{
	int size = findSize(str);
	for (int i = 0; i < size; i++)
	{
		if (isWord(str[i]) && str[i] >= 'a' && !isWord(str[i - 1]))
		{
			str[i] -= 32;
		}
	}
}

char* CharAddress(char* str, char ch)
{
	int size = findSize(str);
	for (int i = 0; i < size; i++)
	{
		if (str[i] == ch) 
		{
			return str + i;
		}
	}
	return 0;
}

char* SubAddress(char* str, char* substr)
{
	int strSize = findSize(str);
	int substrSize = findSize(substr);

	for (int i = 0; i < strSize; i++)
	{
		int cnt = 0;
		int tmp = i;
		for (int j = 0; j < substrSize; j++) 
		{
			if (str[i] != substr[j])
			{
				break;
			}
			i++;
			cnt++;
		}
		if (cnt == substrSize)
		{
			return str + tmp;
		}
	}

	return 0;
}
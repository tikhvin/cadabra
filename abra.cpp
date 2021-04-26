#include <iostream>
#include <string>

class abra_int
{
	static const int base = 10, size = 25;
	int digits[size];

public:
	abra_int()
	{
		for (int i = 0; i < size; i++) 
		{
			digits[i] = 0;
		}
	}

	abra_int(int number) 
	{
		int counter = size - 1;

		while (number != 0)
		{
			digits[counter--] = number % base;
			number /=  base;
		}

		for (int i = counter; i >= 0; i--)
		{
			digits[i] = 0;
		}
	}

	abra_int(int array[])
	{
		for (int i = 0; i < size; i++)
		{
			digits[i] = array[i];
		}
	}

	abra_int(const abra_int& number)
	{
		for (int i = 0; i < size; i++)
		{
			digits[i] = number.digits[i];
		}
	}

	abra_int& operator=(const abra_int& number)
	{
		for (int i = 0; i < size; i++)
		{
			digits[i] = number.digits[i];
		}

		return *this;
	}

	friend bool operator>(const abra_int &a, const abra_int &b);
	friend bool operator==(const abra_int &a, const abra_int &b);
	friend abra_int operator+(const abra_int &left, const abra_int &right);
	friend std::ostream& operator<<(std::ostream& out, const abra_int& number);
};

bool operator>(const abra_int &left, const abra_int &right)
{
	bool flag = 0;

	for (int i = 0; i < abra_int::size; i++)
	{
		if (left.digits[i] > right.digits[i])
		{
			flag = 1;
			break;
		}
		else
		{
			if (left.digits[i] < right.digits[i])
			{
				flag = 0;
				break;
			}
		}
	}

	return flag;
}

bool operator==(const abra_int &left, const abra_int &right)
{
	for (int i = 0; i < abra_int::size; i++)
	{
		if (left.digits[i] != right.digits[i])
		{
			return 0;
		}
	}

	return 1;
}

abra_int operator+(const abra_int &left, const abra_int &right)
{
	abra_int result;
	int tmp, flag = 0;

	for (int i = abra_int::size - 1; i > 0; i--)
	{
		tmp = left.digits[i] + right.digits[i];
		result.digits[i] = (tmp + flag) % abra_int::base;
		flag = (tmp + flag) / abra_int::base;
	}

	return result;
}

std::ostream& operator<<(std::ostream& out, const abra_int& number)
{
	int position = 0;

	for (int i = 0; i < abra_int::size; i++)
	{
		if (number.digits[i] == 0)
		{
			position++;
		}
		else
		{
			break;
		}
	}

	if (position == abra_int::size)
	{
		out << "0";
	}

	for (int i = position; i < abra_int::size; i++)
	{
		out << number.digits[i];
	}

	return out;
}

void easter_egg()
{
	char array[] = "ABRACADABRA";

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << " ";
		}

		for (int j = 0; j < 11 - i; j++)
		{
			std::cout << array[j] << " ";
		}

		std::cout << std::endl;
	}
}

void ready()
{
	std::string answer;
	std::cin >> answer;

	while (answer != "no" and answer != "yes")
	{
		if (answer == "abracadabra")
		{
			easter_egg();
			continue;
		}

		std::cout << "I don't understand you, son." << std::endl;
		std::cout << "Say it again: ";
		std::cin >> answer;
	}

	if (answer == "yes")
	{
		std::cout << std::endl;
	} 
	else if (answer == "no") 
	{
		std::cout << ":(" << std::endl;
		exit(0);
	}
}

int guess()
{
	int number, counter = 1;
	int left = 1, right = 9999;

	std::string answer;
	std::cout << "Say '<', '=' or '>' if your number is less, equal or greater than mine." << std::endl;

	while (counter < 15)
	{
		number = (left + right) / 2;
		std::cout << "I think it's " << number << "..." << std::endl;
		std::cout << "[" << counter << "] ";
		std::cin >> answer;

		if (answer == "<")
		{
			right = number - 1;
		}
		else if (answer == "=")
		{
			std::cout << std::endl;
			std::cout << "Heh, this was easier than I thought." << std::endl;
			return number;
		}
		else if (answer == ">")
		{
			left = number + 1;
		}
		else
		{
			std::cout << "Strange symbol, is it something in Latin?" << std::endl;
			counter--;
		}

		counter++;
	}

	std::cout << "Try again later, I'm not in my best shape today." << std::endl;
	exit(0);
}

void check(int code)
{
	if (code != 6765)
	{
		std::cout << "Unfortunately, you are not the chosen one." << std::endl;
		exit(0);
	}
	else
	{
		std::cout << "Congratulations, here's your secret code!" << std::endl;
	}
}

int fibonacci(abra_int number)
{
	int counter = 2;
	abra_int f_n = 1, f_1 = 1, f_2 = 1;

	while (number > f_n)
	{
		f_n = f_1 + f_2;
		f_1 = f_2;
		f_2 = f_n;
		counter++;
	}

	return counter;
}

void print(char array[])
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << " ";
		}

		for (int j = 0; j < 11 - i; j++)
		{
			std::cout << array[j] << " ";
		}

		std::cout << std::endl;
	}
}

int main()
{
	std::cout << "Hello, stranger! My name is Quintus Serenus Sammonicus." << std::endl;
	std::cout << "Do you want to learn my secret magic spell?" << std::endl;
	std::cout << "Just say 'yes' or 'no': ";
	ready();

	std::cout << "Pick a number from 1 to 9999 and I'll quess it." << std::endl;
	int number = guess();
	check(number);

	int array_1[25] = {0, 0, 0, 0, 0, 8, 3, 6, 2, 1, 1, 4, 3, 4, 8, 9, 8, 4, 8, 4, 1, 6, 2, 1, 2};
	int array_2[25] = {0, 2, 9, 8, 6, 1, 1, 1, 2, 6, 8, 1, 8, 9, 7, 7, 0, 6, 6, 9, 1, 1, 7, 8, 7};
	int array_3[25] = {0, 0, 0, 0, 3, 5, 4, 2, 2, 4, 8, 4, 8, 1, 7, 9, 2, 6, 1, 9, 0, 8, 3, 1, 0};

	abra_int code(number);
	abra_int quintus(array_1);
	abra_int serenus(array_2);
	abra_int sammonicus(array_3);

	char pizza[11];
	int key_1(fibonacci(code + quintus));
	int key_2(fibonacci(code + serenus));
	int key_3(fibonacci(code + sammonicus));

	pizza[0] = pizza[3] = pizza[5] = pizza[7] = pizza[10] = key_1;
	pizza[1] = pizza[8] = key_1 + 1;
	pizza[2] = pizza[9] = key_2;
	pizza[4] = key_3 - 1;
	pizza[6] = key_3;

	print(pizza);
	return 0;
}

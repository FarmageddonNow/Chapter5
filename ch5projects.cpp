#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>

int q4();
void sortmerge(std::ifstream& file1, std::ifstream& file2, std::ofstream& file3);
int q7();
void processgrade(std::ifstream& file1, std::ofstream& file2);
int q9();
void corrector(std::ifstream& file1, std::ofstream& file2);

int main()
{
	std::ifstream inputFile1;
	std::ofstream outputFile1;

	inputFile1.open("../q12in.txt");
	if (inputFile1.fail())
	{
		std::cout << "Input file opening failed.\n";
		_getch();
		exit(1);
	}
	outputFile1.open("../q12out.txt");
	if (outputFile1.fail())
	{
		std::cout << "Output file opening failed.\n";
		_getch();
		exit(1);
	}

	corrector(inputFile1, outputFile1);

	inputFile1.close();
	outputFile1.close();

	_getch();
	return 0;
}

void corrector(std::ifstream& file1, std::ofstream& file2)
{
	char c1 = '1', c2 = '2', c3 = '3', c4 = '4', c5 = '5', c6 = '6', c7 = '7';

	file1.get(c1);
	while (!file1.eof())
	{	
		file2 << c1;
		
		if ((c1 == 'c'))
		{
			file1.get(c2);
			if (file1.eof())
			{				
				break;
			}
			file1.get(c3);
			if (file1.eof())
			{
				file2 << c2;
				break;
			}
			file1.get(c4);
			if (file1.eof())
			{
				file2 << c2 << c3;
				break;
			}
			file1.get(c5);
			if (file1.eof())
			{
				file2 << c2 << c3 << c4;
				break;
			}
			file1.get(c6);
			if (file1.eof())
			{
				file2 << c2 << c3 << c4 << c5;
				break;
			}
			file1.get(c7);
			if (file1.eof())
			{
				file2 << c2 << c3 << c4 << c5 << c6;
				break;
			}

			if ((c2 == 'i') && (c3 == 'n') && (c4 == ' ') && (c5 == '<') && (c6 == '<'))
			{
				c5 = '>';
				c6 = '>';
			}
			else if ((c2 == 'o') && (c3 == 'u') && (c4 == 't') && (c5 == ' ') && (c6 == '>') && (c7 == '>'))
			{
				c6 = '<';
				c7 = '<';
			}
			
			file2 << c2 << c3 << c4 << c5 << c6 << c7;
			
		}
		file1.get(c1);
	}
		
	
}

int q9()
{
	std::ifstream inputFile1;
	std::ofstream outputFile1;
	// Camelcase/Camelcaps naming convention

	inputFile1.open("../q9in.txt");
	if (inputFile1.fail())
	{
		std::cout << "Input file opening failed.\n";
		_getch();
		exit(1);
	}
	outputFile1.open("../q9out.txt");
	if (outputFile1.fail())
	{
		std::cout << "Output file opening failed.\n";
		_getch();
		exit(1);
	}

	while (!inputFile1.eof())
	{
		processgrade(inputFile1, outputFile1);
	}

	inputFile1.close();
	outputFile1.close();

	_getch();
	return 0;
}

void processgrade(std::ifstream& file1, std::ofstream& file2)
{
	char nextChar;
	int count = 0;
	double nextNum, sum = 0, avg;

	while (count < 2)
	{
		file1.get(nextChar);
		file2 << nextChar;
		std::cout << nextChar;
		if (nextChar == ' ')
		{
			count++;
		}
	}
	count = 0; 
	std::cout << std::endl;
	while ((count < 10) && (file1 >> nextNum))
	{
		file2 << nextNum << ' ';
		sum = sum + nextNum;
		count++;
	}
	avg = sum/count;
	file2 << avg;
}

int q7()
{
	std::ifstream fin1, fin2;
	std::ofstream fout;

	fin1.open("../q5in_1.txt");
	if (fin1.fail())
	{
		std::cout << "Input file opening failed.\n";
		_getch();
		exit(1);
	}
	fin2.open("../q5in_2.txt");
	if (fin2.fail())
	{
		std::cout << "Input file opening failed.\n";
		_getch();
		exit(1);
	}
	fout.open("../q5out.txt");
	if (fout.fail())
	{
		std::cout << "Output file opening failed.\n";
		_getch();
		exit(1);
	}
	sortmerge(fin1, fin2, fout);

	fin1.close();
	fin2.close();
	fout.close();

	_getch();
	return 0;
}

void sortmerge(std::ifstream& file1, std::ifstream& file2, std::ofstream& file3)
{
	int first, second;
	
	file1 >> first;
	file2 >> second;

	while (!file1.eof() && !file2.eof())
	{
		if (first <= second)
		{
			file3 << first << std::endl;
			file1 >> first;
		}
		else
		{
			file3 << second << std::endl;
			file2 >> second;
		}
	}
	if (file1.eof())
	{
		while (file2 >> second)
		{
			file3 << second << std::endl;
		}
	}
	else if (file2.eof())
	{
		while (file1 >> first)
		{
			file3 << first << std::endl;
		}
	}
}

int q4()
{
	using namespace std;

	ifstream fin;

	cout << "This program will get the average and standard deviation of the numbers in a text file." << endl;

	fin.open("../q4in.txt");
	if (fin.fail())
	{
		cout << "Input file opening failed.\n";
		_getch();
		exit(1);
	}

	int count = 0;
	double next, sum, avg, stddev;
	while (fin >> next)
	{
		count++;
		sum = sum + next;
	}
	if (count == 0)
	{
		cout << "There are no numbers in the file!" << endl;
		return -1;
		// Rahul: when there is error, return "-1" as matter of personal preference
	}
	avg = sum/count;

	// Below is inefficient code
	/*double n1, n2, n3, n4, n5, n6, a, stddev;
	fin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;
	a = (n1 + n2 + n3 + n4 + n5 + n6)/6;*/

	cout << "The average of the numbers in q4in.txt is " << avg << endl;

	fin.close();

	fin.open(".././././././../chapter 5/../VSMacro80/././../chapter 5/q4in.txt"); 
	// The path to q4in.txt is relative to the executable's path.
	// The "../" implies that the file is one-level above the current loction
	// "./" implies the current location
	if (fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	sum = 0;
	while (fin >> next)
	{
		sum = sum + pow(next - avg, 2);
		// Note: just reusing 'sum' for formula for standard deviation so I don't have to declare a new variable.
	}
	stddev = sqrt(sum)/avg;
	cout << "The standard deviation of the numbers in q4in.txt is " << stddev << endl;
	
	fin.close();
	
	ofstream fout;
	fout.open("../q4out.txt");
	if (fout.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}

	fout << "The average is " << avg << endl
		 << "The standard deviation is " << stddev << endl;

	fout.close();
	cout << "Done!" << endl;

	_getch();
	return 0;
}



// question 4, 7, 9, 12
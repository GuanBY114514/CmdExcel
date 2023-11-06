#pragma once
//Start:Chart_Basic_Input_output
#ifndef CHARTBASICIO_H
#define CHARTBASICIO_H
#endif // !CHARTBASICIO_H
#include<iostream>
#include"function.h"
#include"exitorerror.h"
class ChartIO
{
public:
	void welcome(void);
	void view_chart(int r, int c, int content[2000][2000]);
	void open_file(std::string file_open_path);
	void get_chart(int r, int c, int content[2000][2000], char mode);
	void get_help(void);
	int exit_command(char File_mode);
	int exit_program(int exit_value, int r, int l, int content[2000][2000]);
};
Cellsfunc cedfn;
void ChartIO::welcome(void)
{
	std::cout << "Welcome to CmdExcel" << std::endl;
	std::cout << "Type 'o' to open a file " << std::endl;
	std::cout << "Type 'n' to creat a new file" << std::endl;
	std::cout << "Type 'h' to see the history(Can't used now)" << std::endl;
	std::cout << "Type 'e' to exit" << std::endl;
}
void ChartIO::view_chart(int r, int c, int content[2000][2000])
{
	using namespace std;
	system("cls");
	int maxx = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			maxx = max(maxx, content[i][j]);
		}
	}
	int num_digit = cedfn.count_digit(maxx);
	for (int i = 0; i <= c; i++)
	{
		cout << '/' << i;
		for (int j = 1; j <= num_digit; j++)
		{
			std::cout << ' ';
		}
	}
	cout << endl;
	num_digit++;
	for (int i = 1; i <= r; i++)
	{
		cout << '/' << i;
		for (int j = 1; j <= num_digit; j++)
		{
			cout << ' ';
		}
		for (int j = 1; j <= c; j++)
		{
			cout << content[i][j];
			for (int k = 1; k <= num_digit - cedfn.count_digit(content[i][j]) + 1; k++)
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
	cout << "Command:\n";
}
void ChartIO::open_file(std::string file_open_path_str)
{
	std::cout << "Please type the path and the filename of your chart\nForm:Decive:/Folder/...../filename\n";
	const char* file_open_path="D:/ce.mlx\0";
	while (std::cin >> file_open_path_str)
	{
		file_open_path = file_open_path_str.c_str();
		if (freopen(file_open_path, "r", stdin) == NULL)
		{
			std::cout << "File is not found,please check your path and your filename\n";
		}
		break;
	}
	freopen(file_open_path, "r", stdin);
}
void ChartIO::get_chart(int r, int c, int content[2000][2000],char mode)
{
	using namespace std;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> content[i][j];
		}
	}
	return;
}
void ChartIO::get_help(void)
{
	using namespace std;
	cout << endl;
	cout << "Commands:" << endl;
	cout << "For the chart content:" << endl;
	cout << "write --rewrite or write the cells" << endl;
	cout << "add --add the cells" << endl;
	cout << "cls --clean the screen" << endl;
	cout << "view -- review the chart cells" << endl;
	cout << "select --select the cells to change it" << endl;
	cout << "For the function:" << endl;
	cout << "sum --summation of the select cells" << endl;
	cout << endl;
}
int ChartIO::exit_command(char File_mode)
{
	int exit_value = 0;
	using namespace std;
	if (File_mode == 'o')
	{
		cout << "Do you want to save the changes ?(Y/N)" << endl;
		char isp;
		while (1)
		{
			std::cin >> isp;
			if (isp == 'Y')
			{
				exit_value = 1;
				break;
			}
			else if (isp == 'N')
			{
				exit_value = 2;
				break;
			}
			else
			{
				cout << "Please type the correct letter (Y/N)" << endl;
				exit_value = 0;
			}
		}
	}
	else
	{
		cout << "Do you want to save this chart? (Y/N)" << endl;
		char isp;
		while (1)
		{
			cin >> isp;
			if (isp == 'Y')
			{
				exit_value = 1;
				break;
			}
			else if (isp == 'N')
			{
				exit_value = 2;
				break;
			}
			else
			{
				cout << "Please type the correct letter (Y or N)" << endl;
				exit_value = 0;
			}
		}
	}
	return exit_value;
}
int ChartIO::exit_program(int exit_value, int r, int l, int content[2000][2000])
{
	using namespace std;
	if (exit_value == 2)
	{
		cout << "Command executed, program will exit in 5 seconds";
		_sleep(5000);
		return Exit_with_no_save;
	}
	else
	{
		string F_P;
		cout << "Please type the path that you want to save your chart, From: Decive:/path/.../(filename).extension" << endl;
		cin >> F_P;
		const char* file_path_exit = F_P.c_str();
		cout << "Saving successfully,the program will exit in 5 seconds";
		freopen( file_path_exit, "w", stdout);
		cout << r << " " << l << endl;
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= l; j++)
			{
				cout << content[i][j] << " ";
			}
			cout << endl;
		}
		return Exit_with_save;
	}
}
//End:Chart_Basic_Input_output
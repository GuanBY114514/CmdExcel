#include<bits/stdc++.h>
#include<Windows.h>
#include"headers/function.h"
#include"headers/chartbasicio.h"
#include"headers/history.h"
#include"headers/exitorerror.h"
#pragma warning(disable:4996)
using namespace std;
//函数类声明
Chartfunc chartfunc;
ChartIO chart_IO;
Cellsfunc cellsfunc;
History history;
//表格内容
int chartn[2000][2000];
//表格列
int table_col = 0;
//表格行
int table_row = 0;
//文件路径
string file_path;
int main()
{
	chart_IO.welcome();
	char file_mode = 'n';//文件读写模式
	chartfunc.tolow(file_mode);
	FILE* stream1;
	while (cin >> file_mode)
	{
		if (file_mode == 'e')
		{
			cout << "Command Excued\nThis program will exit in 5 seconds" << endl;
			_sleep(5000);
			return Exit_before_open;
		}
		else if (file_mode == 'o')
		{
			chart_IO.open_file(file_path);
			break;
		}
		else if (file_mode == 'n')
		{
			cout << "Please type the row and collum of the chart you want to create" << endl;
			break;
		}
		else
		{
			cout << "Command error" << endl;
		}
	}
	if (file_mode == 'n')
	{
		while (cin >> table_row >> table_col)
		{
			if (table_row > 0 && table_row < 2000 && table_col > 0 && table_col < 2000)
			{
				break;
			}
			else
			{
				cout << "The row or column of this chart is wrong, it must be an positive integer and less than 2000" << endl;
			}
		}
		system("cls");
		std::cout << "Please type the data of the chart" << endl;
	}
	else
	{
		cin >> table_row >> table_col;
	}
	chart_IO.get_chart(table_row, table_col, chartn, file_mode);
	//命令
	string commd = "";
	//退出值
	int exitvalue = 0;
	system("cls");
	chart_IO.view_chart(table_row, table_col, chartn);
	cout << endl;
	cout << "Type command" <<endl;
	int select_row = 0, select_col = 0;
	freopen_s(&stream1, "CON", "r", stdin);
	//命令功能模块
	while (cin >> commd)
	{
		if (commd == "write")
		{
			cellsfunc.write(select_row, select_col, chartn);
		}
		else if (commd == "help")
		{
			chart_IO.get_help();
		}
		else if (commd == "cls")
		{
			system("cls");
			cout << "Command:" <<endl;
		}
		else if (commd == "view")
		{
			chart_IO.view_chart(table_row, table_col, chartn);
			cout << "Command:" << endl;
		}
		else if (commd == "select")
		{
			select_row = 0;
			select_col = 0;
			while (!cellsfunc.check_select(select_row, select_col))
			{
				printf("Please type cell you want to select \n Form: row,col \n");
				scanf("%d,%d", &select_row, &select_col);
			}
				chart_IO.view_chart(table_row, table_col, chartn);
				cout << "Select successfully\nCommands:";
		}
		else if (commd == "sum")
		{
			//empty
		}
		else if (commd == "max")
		{
			cellsfunc.fmax(select_row, select_col, chartn);
			chart_IO.view_chart(table_row, table_col, chartn);
		}
		else if (commd == "min")
		{
			cellsfunc.fmin(select_row, select_col, chartn);
			chart_IO.view_chart(table_row, table_col, chartn);
		}
		else if (commd == "average")
		{
			cellsfunc.average(select_row, select_col, chartn);
			system("cls");
			cout << "Command exceute Syccessfully\n";
			chart_IO.view_chart(table_row, table_col, chartn);
		}
		//求平均值模块
		else if (commd == "addrow")
		{
			string cod;
			table_row = cellsfunc.addrow(table_row, cod);
		}
		//加行
		else if (commd == "addcol")
		{
			string cod;
			table_col = cellsfunc.addcol(table_col, cod);
		}
		//加列
		else if (commd == "chkselect")
		{
			printf("select_row:%d select_col:%d", select_row, select_col);
		}
		else if (commd == "formula")
		{

		}
		else if (commd == "exit")
		{
			exitvalue = chart_IO.exit_command(file_mode);
			//退出模块
			if (exitvalue != 0)
			{
				break;
			}
		}
		else
		{
			cout << "Command not found, please type 'help' for help" <<  endl;
			_sleep(2000);
		}
		chart_IO.view_chart(table_row, table_col, chartn);
	}
	int exit_program_value = chart_IO.exit_program(exitvalue, table_row, table_col, chartn);
	_sleep(5000);
	return exit_program_value;
}
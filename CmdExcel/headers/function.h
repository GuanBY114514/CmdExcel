#pragma once
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include"exitorerror.h"
#ifndef FUNCTION_H
#define FUNCTION_H
#endif // !FUNCTION_H
class Chartfunc
{
public:
	//转大写
	void toupper(char x);
	//转小写
	void tolow(char x);
	//字符串转整数
	int str_to_int(std::string s, size_t len);
}chartfun;
//-----------------------------------------------------------------------------------------
class Cellsfunc
{
public:
	//选择检查
	bool check_select(int s_row, int s_col);
	//选择单元格
	void select(int s_row, int s_col);
	//加行
	int addrow(int nowrow, std::string number);
	//加列
	int addcol(int nowcol, std::string number);
	//数位数
	int count_digit(int x);
	//平均值
	void average(int select_rowl, int select_coll, int content[2000][2000]);
	//写入
	void write(int st_row, int st_col, int content[2000][2000]);
	void fmax(int st_row, int st_col, int content[2000][2000]);
}cellsfun;
//------------------------------------------------------------------------------------------
bool Cellsfunc::check_select(int s_row, int s_col)
{
	if (s_row > 0 && s_col > 0 )
	{
		return true;
	}
	else if(s_row > 2000 || s_col > 2000)
	{
		std::cerr << "Exceeding Table Size" << std::endl;
		return false;
	}
	else
	{
		std::cerr << "The select cells is wrong or you haven't select a cells, type 'select select' to get more help " << std::endl;
		return false;
	}
}
void Cellsfunc::select(int s_row, int s_col)
{
	int tmp_r = 0, tmp_c = 0;
	while (!check_select(tmp_r, tmp_c))
	{
		printf("Please type cell you want to select \n Form: row,col \n");
		scanf("%d,%d", &tmp_r, &tmp_c);
	}
	s_row = tmp_r;
	s_col = tmp_c;
	system("cls");
	return;
}
void Chartfunc::toupper(char x)
{
	if (x >= 'A' && x <= 'Z')
	{
		return;
	}
	else if (x >= 'a' && x <= 'z')
	{
		x -= ' ';
		return;
	}
	else
	{
		printf("%x", Is_not_char);
		_sleep(2000);
		return;
	}
}
void Chartfunc::tolow(char x)
{
	if (x >= 'A' && x <= 'Z')
	{
		x += ' ';
		return;
	}
	else if (x >= 'a' && x <= 'z')
	{
		return;
	}
	else
	{
		printf("%x", Is_not_char);
		_sleep(2000);
		return;
	}
}
int Chartfunc::str_to_int(std::string s, size_t len)
{
	int ans = 0;
	bool pls = false;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '-')
		{
			pls = true;
		}
		else
		{
			ans *= 10;
			ans += s[i] - '0';
		}
	}
	if (pls == true)
	{
		return -1 * ans;
	}
	else
	{
		return ans;
	}
}
int Cellsfunc::count_digit(int x)
{
	if (x == 0)
	{
		return 1;
	}
	int tmp = x;
	int ans = 0;
	while (tmp)
	{
		ans++;
		tmp /= 10;
	}
	return ans;
}
int Cellsfunc::addrow(int nowrow, std::string number)
{
	using namespace std;
	std::cout << "Please type the number of add row" << std::endl;
	std::cin >> number;
	if (nowrow + chartfun.str_to_int(number, number.size()) < 1)
	{
		std::cout << "Error:Added value is wrong, please type 'addrow help' to get help" << std::endl;
		return 0;
	}
	else
	{
		nowrow += chartfun.str_to_int(number, number.size());
		std::cout << "Command has run successfully" << std::endl;
		cout << endl << "Command:" << endl;
		return nowrow;
	}
	if (number == "help")
	{
		cout << "Command: addrow -v" << endl;
		cout << "-v --if the value is positive number, means add rows" << endl;
		cout << "--if the value is a negative, means minus rows,but the abs(v) cannot upper than chart's row" << endl;
		cout << endl << "Command:" << endl;
		return 0;
	}
}
int Cellsfunc::addcol(int nowcol, std::string number)
{
	using namespace std;
	cout << "Please type the number of added col" << endl;
	cin >> number;
	if (nowcol + chartfun.str_to_int(number, number.size()) < 1)
	{
		cout << "Error:Added value is wrong, please type 'addrow help' to get help" << endl;
		return Exit_func_wrong;
	}
	else
	{
		nowcol += chartfun.str_to_int(number, number.size());
		cout << "Command has run successfully" << endl;
		return nowcol;
	}
	if (number == "help")
	{
		cout << "Command: addcol -v" << endl;
		cout << "-v --if the value is positive number, means add columns" << endl;
		cout << "--if the value is a negative, means minus columns,but the abs(v) cannot upper than chart's column" << endl;
		return Exit_func_help;
	}
}
void Cellsfunc::average(int select_rowl, int select_coll, int content[2000][2000])
{
	int s_row = 0, s_col = 0, e_row = 0, e_col = 0;
	std::cout << "Please type the cells you want to calculate \n" << "Form: start_row,start_col end_row,end_col" << std::endl;
	scanf("%d,%d", &s_row, &s_col);
	scanf("%d,%d", &e_row, &e_col);
	if (s_row == e_row && s_col == e_col)
	{
		printf("%x", Start_to_end_is_no_cells);
		_sleep(2000);
		return;
	}
	int sum = 0, cnt_cell = 0;
	for (int i = s_row; i <= e_row; i++)
	{
		for (int j = s_col; j <= e_col; j++)
		{
			sum += content[i][j];
			cnt_cell++;
		}
	}
	content[select_rowl][select_coll] = sum / cnt_cell;
	return;
}
void Cellsfunc::write(int st_row, int st_col, int content[2000][2000])
{
	if (cellsfun.check_select(st_row, st_col))
	{
		int cont = 0;
		std::cout << "Please enter the value for the selected cell" << std::endl;
		std::cin >> cont;
		content[st_row][st_col] = cont;
		return;
	}
	else
	{ }
}
void Cellsfunc::fmax(int st_row, int st_col, int content[2000][2000])
{
	int s_row, s_col, e_row, e_col;
	std::cout << "Please the cells you want to find\nForm:start_row,start_column end_row,end_cloumn\n";
	while (true)
	{
		if (scanf("%d,%d", &s_row, &s_col) && scanf("%d,%d", &e_row, &e_col))
		{
			break;
		}
		else
		{
			std::cerr << "From is wrong\nMust be start_row,start_column end_row,end_cloumn\n";
		}
	}
	int maxx = 0;
	for (int i = s_row; i < e_row; i++)
	{
		for (int j = s_col; j <= e_col; j++)
		{
			maxx = max(maxx, content[i][j]);
		}
	}
	content[st_row][st_col] = maxx;
	return;
}
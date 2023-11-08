#pragma once
#ifndef HISTORY_H
#define HISTORY_H
#endif // !HISTORY_H
#pragma warning(disable:4996)
#include<stdio.h>
#include<ctime>
class History
{
public:
	//检查历史文件
	bool check_history_file(void);
	//历史文件预览
	void view_history(std::string recive_path_str);
	void save_history(char File_mode);
private:
	const char* history_file = "D:/CmdExcel.history";
	int history_num = 0;
	int file_list[11] = {};
	std::string save_path[11];
	std::string last_save_time[11];
};
bool History::check_history_file(void)
{
	if (freopen(History::history_file, "r", stdin) == NULL)
	{
		freopen("CON", "r", stdin);
		std::cerr << "No history!" << std::endl;
		_sleep(2000);
		return false;
	}
	return true;
}
void History::view_history(std::string recive_path_str)
{
	using namespace std;
	if (History::check_history_file() == true)
	{
		std::cin >> History::history_num;
		size_t max_time_len = 0, max_path_len = 0;
		for (int i = 1; i <= History::history_num; i++)
		{
			std::cin >> History::file_list[i] >> History::last_save_time[i] >> History::save_path[i];
			max_time_len = max(max_time_len, History::last_save_time[i].size());
			max_path_len = max(max_path_len, History::save_path[i].size());
		}
		system("cls");
		for (int i = 0; i <= History::history_num; i++)
		{
			if (i == 0)
			{
				cout << "num ";
				cout << "path";
				for (int j = 4; j <= max_path_len; j++)
				{
					cout << ' ';
				}
				cout << "time";
				for (int j = 4; j <= max_time_len; j++)
				{
					cout << ' ';
				}
				cout << endl;
			}
			else
			{
				cout << i << "   ";
				cout << History::save_path[i];
				for (size_t j = History::save_path[i].size(); j <= max_path_len; j++)
				{
					cout << ' ';
				}
				cout << History::last_save_time[i];
				for (size_t j = History::last_save_time[i].size(); j <= max_time_len; j++)
				{
					cout << ' ';
				}
				cout << endl;
			}
		}
		char open_num = 0;
		freopen("CON", "r", stdin);
		while (cin >> open_num)
		{
			if (open_num > 0 && open_num <= history_num)
			{

				recive_path_str = save_path[open_num - '0'];
				return;
			}
			else if (open_num == 'e')
			{
				return;
			}
			else
			{
				cout << "No files!\n";
			}
		}
		
	}
	else
	{
		return;
	}
}
void History::save_history(char File_mode)
{

}
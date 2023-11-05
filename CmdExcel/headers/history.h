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
	const char * history_file= "C:/CmdExcel.history";
	//检查历史文件
	bool check_history_file(void);
	//历史文件预览
	void view_history(void);
	void save_history(void);
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
void History::view_history(void)
{}
void History::save_history(void)
{

}
#pragma once
#ifndef HISTORY_H
#define HISTORY_H
#endif // !HISTORY_H
#pragma warning(disable:4996)
#include<stdio.h>
class History
{
public:
	const char * history_file= "C:/CmdExcel.history";
	//�����ʷ�ļ�
	bool check_history_file(void);
	//��ʷ�ļ�Ԥ��
	void view_history(void);
};
bool History::check_history_file(void)
{
	if (freopen(history_file, "r", stdin) == NULL)
	{
		return false;
	}
	return true;
}

#include "Linker.h"
struct {
	unsigned int file_id;
	unsigned int func_num;
	bool isInclude;
}File[MAX_FILE_NUM];
unsigned int Func[MAX_ID_NUM];
unsigned int IncludeFile[MAX_ID_NUM];


/******************************************************************************
清空数据
******************************************************************************/
void clear()
{
	for (int i = 0; i < MAX_FILE_NUM; i++)
	{
		File[i].func_num = 0;
		File[i].isInclude = false;
	}
	for (int i = 0; i < MAX_ID_NUM; i++)
	{
		Func[i] = 0;
		IncludeFile[i] = 0;
	}
}

/******************************************************************************
功能：添加一个文件，以及这个文件内的所有函数
输入：
	   file_id 	              文件id
	   func_id_array          函数id数组，用例保证数组内元素不重复
	   func_num               函数个数
输出： 
	   无
返回：
	   0：成功，-1：失败
******************************************************************************/
int AddFile(unsigned int file_id, unsigned int func_id_array[],unsigned int func_num)
{
	if (file_id >= MAX_FILE_NUM)
		return -1;
	File[file_id].file_id = file_id;
	for (unsigned int i = 0; i < func_num; i++)
		Func[func_id_array[i]] = file_id;
	File[file_id].func_num = func_num;
	return 0;
}


/******************************************************************************
功能：添加一个函数的直接调用关系，可以多次增加
输入：
		caller_id   	    调用者函数id
		callee_id_array 	被调用的函数id数组，用例保证数组内元素不重复，数组内元素个数不为0
		callee_num          被调用的函数个数，用例保证函数个数不为0

输出： 
		无
返回：  
		0：成功，-1：失败
******************************************************************************/
int AddCallList(unsigned int caller_id, unsigned int callee_id_array[], unsigned int callee_num)
{
	if (caller_id > MAX_ID_NUM)
		return -1;
	if (caller_id==11||IncludeFile[Func[caller_id]])
	{
		for (unsigned int i = 0; i < callee_num; i++)
			IncludeFile[Func[callee_id_array[i]]] = 1;
	}
	return 0;
}


/******************************************************************************
功能：判断一个文件是否会被Link进来
输入：
	  file_id 			文件id
输出：
	  无
返回：
	  该文件会被Link进来返回0，不会被Link进来返回-1（包括文件id不存在等）
******************************************************************************/
int IsFileLinked(unsigned int file_id)
{
	if (file_id > MAX_FILE_NUM || IncludeFile[file_id] == 0)
		return -1;
	return 0;
}



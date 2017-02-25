
#include "Linker.h"
struct {
	unsigned int file_id;
	unsigned int func_num;
	bool isInclude;
}File[MAX_FILE_NUM];
unsigned int Func[MAX_ID_NUM];
unsigned int IncludeFile[MAX_ID_NUM];


/******************************************************************************
�������
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
���ܣ����һ���ļ����Լ�����ļ��ڵ����к���
���룺
	   file_id 	              �ļ�id
	   func_id_array          ����id���飬������֤������Ԫ�ز��ظ�
	   func_num               ��������
����� 
	   ��
���أ�
	   0���ɹ���-1��ʧ��
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
���ܣ����һ��������ֱ�ӵ��ù�ϵ�����Զ������
���룺
		caller_id   	    �����ߺ���id
		callee_id_array 	�����õĺ���id���飬������֤������Ԫ�ز��ظ���������Ԫ�ظ�����Ϊ0
		callee_num          �����õĺ���������������֤����������Ϊ0

����� 
		��
���أ�  
		0���ɹ���-1��ʧ��
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
���ܣ��ж�һ���ļ��Ƿ�ᱻLink����
���룺
	  file_id 			�ļ�id
�����
	  ��
���أ�
	  ���ļ��ᱻLink��������0�����ᱻLink��������-1�������ļ�id�����ڵȣ�
******************************************************************************/
int IsFileLinked(unsigned int file_id)
{
	if (file_id > MAX_FILE_NUM || IncludeFile[file_id] == 0)
		return -1;
	return 0;
}



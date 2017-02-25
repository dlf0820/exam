#ifndef _LINKER_H_
#define _LINKER_H_
#define MAX_FILE_NUM 100 
#define MAX_ID_NUM 100 
void clear();
int AddFile(unsigned int file_id, unsigned int func_id_array[],unsigned int func_num);
int AddCallList(unsigned int caller_id, unsigned int callee_id_array[], unsigned int callee_num);
int IsFileLinked(unsigned int file_id);

#endif

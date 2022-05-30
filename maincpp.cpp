#include"headfile.h"


int main(int argc,char*argv[])
{
	
	string src = argv[1], dst = argv[2];
	syncFolders(src, dst);

	return 0;
}
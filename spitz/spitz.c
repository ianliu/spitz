#include "spitz.h"

__thread int workerid = -1;
int nworkers;

int spitz_get_worker_id(void)
{
	return workerid;
}

int spitz_get_num_workers(void)
{
	return nworkers;
}

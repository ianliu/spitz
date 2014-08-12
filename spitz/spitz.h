#ifndef __SPITZ_H__
#define __SPITZ_H__

/*
 * Returns the worker id. If this method is called in a non-worker entity, it
 * returns -1.
 */
int spitz_get_worker_id(void);

/*
 * Returns the number of workers in this process.
 */
int spitz_get_num_workers(void);

#endif /* __SPITZ_H__ */

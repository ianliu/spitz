#include <barray.h>
#include <stdio.h>

/*---------------------------------------------------------------------------*/
/* JOB MANAGER --------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
struct pi_jm {
	int numpoints;
};

void *spits_setup_job_manager(int argc, char *argv[])
{
	struct pi_jm *self = malloc(sizeof(*self));
	self->numpoints = atoi(argv[0]);
	return self;
}

int spits_generate_pit(void *user_data, struct byte_array *ba)
{
	struct pi_jm *self = user_data;
	if (self->numpoints == 0)
		return 0;

	double x = drand48();
	double y = drand48();
	byte_array_pack64(ba, x);
	byte_array_pack64(ba, y);
	self->numpoints--;

	return 1;
}

/*---------------------------------------------------------------------------*/
/* WORKER -------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
void *spits_worker_new(int argc, char **argv)
{
	return NULL;
}

void spits_worker_run(void *user_data, struct byte_array *task, struct byte_array *result)
{
	double x, y;
	byte_array_unpack64(task, &x);
	byte_array_unpack64(task, &y);

	uint8_t inside = (x*x + y*y <= 1);
	byte_array_pack8(result, inside);
}

/*---------------------------------------------------------------------------*/
/* COMMIT -------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
struct pi_commit {
	int count;
	int numpoints;
};

void *spits_setup_commit(int argc, char *argv[])
{
	struct pi_commit *self = malloc(sizeof(*self));
	self->count = 0;
	self->numpoints = atoi(argv[0]);
	return self;
}

void spits_commit_pit(void *user_data, struct byte_array *result)
{
	struct pi_commit *self = user_data;

	uint8_t x;
	byte_array_unpack8(result, &x);
	self->count += x;
}

void spits_commit_job(void *user_data, struct byte_array *final_result)
{
	struct pi_commit *self = user_data;
	double pi = 4.0L * self->count / self->numpoints;
	printf("pi = %lf\n", pi);
}

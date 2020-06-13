//
// Created by lox on 13.06.2020.
//

#include "fract.h"

void		thread_create(t_main *data)
{
	int 		i;
	pthread_t	t[NUM_THREADS];
	t_threads	args[NUM_THREADS];

	i = -1;
	while (++i < NUM_THREADS)
	{
		args[i].id = i;
		args[i].data = data;
		if (pthread_create(&t[i], NULL, put_img, args + i))
			on_crash(ERROR_CREATE_THREAD);
	}
	while (i-- > 0)
		if (pthread_join(t[i], NULL))
			on_crash(ERROR_JOIN_THREAD);
}
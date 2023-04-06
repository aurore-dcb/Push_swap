# ifndef FT_H
#define FT_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

typedef struct s_list
{
    int i;
    void *next;
} t_list;

int ft_list_size(t_list *begin);

#endif
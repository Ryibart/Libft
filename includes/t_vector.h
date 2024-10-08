/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:36:42 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 15:54:43 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|t_vector.h|══════════════════════════════════════════════════════════════*

	Purpose:	Header file that defines the `t_vector` structure and 
				prototypes for vector operations. This includes functions 
				for creation, manipulation, and access to dynamic vectors.
				
	Notes:		The `t_vector` structure contains a pointer to memory, 
				element size, allocated size, and the current length of 
				the vector.

*════════════════════════════════════════════════════════════════════════════*/

#ifndef T_VECTOR_H
# define T_VECTOR_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include "libft.h"

# define VECTOR_ERROR -1
# define VECTOR_SUCCESS 1
# define VECTOR_OK 0

typedef struct s_vector
{
	unsigned char	*memory;
	size_t			elem_size;
	size_t			alloc_size;
	size_t			len;
}					t_vector;

int		vector_new(t_vector *src, size_t init_len, size_t elem_size);
void	vector_free(t_vector *src);
int		vector_from(t_vector *dst, void *src, size_t len, size_t elem_size);
int		vector_resize(t_vector *src, size_t target_size);
int		vector_clear(t_vector *src);

int		vector_push_first(t_vector *dst, void *src);
int		vector_push_last(t_vector *dst, void *src);
int		vector_pop_first(void *dst, t_vector *src);
int		vector_pop_last(void *dst, t_vector *src);

int		vector_copy(t_vector *dst, t_vector *src);

void	*vector_get(t_vector *src, size_t index);

int		vector_insert(t_vector *dst, void *elem, size_t index);
int		vector_remove(t_vector *src, size_t index);

int		vector_append(t_vector *dst, t_vector *src);
int		vector_prepend(t_vector *dst, t_vector *src);

void	vector_iter(t_vector *src, void (*f) (void *));
void	*vector_find(t_vector *src, bool (*f) (void *));
int		vector_map(t_vector *dst, t_vector *src, void (*f) (void *));
int		vector_filter(t_vector *dst, t_vector *src, bool (*f) (void *));
int		vector_reduce(void *dst, t_vector *src, void (*f) (void *, void *));

void	vector_sort(t_vector *src, int (*f)(void *, void *));

typedef void	*(*t_typecast_fn)(void *);

void	*cast_to_int(void *element);
void	*cast_to_long(void *element);
void	*cast_to_char(void *element);
void	*cast_to_size_t(void *element);
void	*vector_typecast(t_vector *src, size_t index, t_typecast_fn cast_fn);

#endif

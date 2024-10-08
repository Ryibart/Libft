/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:13:28 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/18 16:51:49 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_return(void *str)
{
	free(str);
	return (NULL);
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count != 0 && size != 0 && count > (SIZE_MAX / size))
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	while (count * size > 0)
	{
		((unsigned char *)ret)[count * size - 1] = 0;
		count--;
	}
	return (ret);
}

char	*gnl_strchr(const char *s, int c)
{
	int		i;
	char	u_c;

	i = 0;
	u_c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == u_c)
			return ((char *)&s[i]);
		i++;
	}
	if (u_c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ret = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

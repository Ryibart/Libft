/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:37:53 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:18 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_count_words|══════════════════════════════════════════════════════════*

	Purpose:	Counts the number of words in a given string `s` separated 
				by the specified delimiter `c`. This function is useful for 
				determining the number of substrings when splitting a string.
				
	Parameters:
					s (IN) -- The input string to be analyzed.
					c (IN) -- The delimiter used to separate words in the string.

	Returns:		The number of words in the string `s` separated by the 
					delimiter `c`.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	if (!s || !*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

/*══|ft_free_arr|═════════════════════════════════════════════════════════════*

	Purpose:	Frees a dynamically allocated array of strings and its 
				individual elements. This function is commonly used to clean 
				up memory after splitting a string into an array of substrings.
				
	Parameters:
					arr (IN/OUT) -- The array of strings to be freed.
					count (IN) -- The number of strings in the array `arr`.

	Returns:		None (void).

*════════════════════════════════════════════════════════════════════════════*/

static void	ft_free_arr(char **arr, int count)
{
	if (arr)
	{
		while (--count >= 0)
			free(arr[count]);
	}
	free(arr);
}

/*══|ft_separate|═════════════════════════════════════════════════════════════*

	Purpose:	Splits a given string `s` into substrings based on the 
				specified delimiter `c`. The resulting substrings are 
				stored in a pre-allocated array `ret`. This function handles 
				memory allocation for the substrings and cleans up in case 
				of an error.
				
	Parameters:
				s (IN) -- The input string to be split.
				ret (OUT) -- Pre-allocated array to store
				the resulting substrings.
				c (IN) -- The delimiter used to split the string.
				i (OUT) -- Pointer to an integer indicating
				the current index in `ret`.

	Returns:	Pointer to the array `ret` with the substrings, or `NULL` 
				in case of an error during memory allocation.

	Notes:		If an error occurs during substring allocation, the function 
				cleans up the previously allocated substrings using 
				`ft_free_arr`.

*════════════════════════════════════════════════════════════════════════════*/

static char	**ft_separate(const char *s, char **ret, char c, int *i)
{
	size_t		word_len;
	const char	*end;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			end = ft_strchr(s, c);
			if (end)
				word_len = end - s;
			else
				word_len = ft_strlen(s);
			ret[*i] = ft_substr(s, 0, word_len);
			if (!ret[*i])
			{
				ft_free_arr(ret, *i);
				return (0);
			}
			(*i)++;
			s += word_len;
		}
	}
	return (ret);
}

/*══|ft_split|════════════════════════════════════════════════════════════════*

	Purpose:	Splits a given string `s` into substrings using the specified 
				delimiter `c`. Returns an array of strings, with each substring 
				representing a word separated by the delimiter. This function 
				allocates memory for the resulting array and its substrings, 
				so care must be taken to free the memory after use.
				
	Parameters:
				s (IN) -- The input string to be split.
				c (IN) -- The delimiter used to split the string into substrings.

	Returns:	A dynamically allocated array of substrings, with each 
				substring representing a word separated by the delimiter. 
				Returns `NULL` if there's an error during memory allocation 
				or if the input string `s` is `NULL`.

	Notes:		The caller is responsible for freeing the returned array and 
				its substrings to avoid memory leaks.

*════════════════════════════════════════════════════════════════════════════*/

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		word_count;

	i = 0;
	word_count = ft_count_words(s, c);
	if (!s)
		return (0);
	ret = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!ret)
		return (0);
	if (!ft_separate(s, ret, c, &i))
		return (0);
	ret[i] = 0;
	return (ret);
}

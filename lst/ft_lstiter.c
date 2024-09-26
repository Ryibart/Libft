/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:03:45 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:45 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_lstiter|═══════════════════════════════════════════════════════════════*

	Purpose:	Applies a given function `f` to each node's content in a 
				linked list. This function iterates through the list, 
				applying the function to the content of each node in sequence.
				
	Parameters:
				lst (IN) -- Pointer to the head of the linked list to iterate.
				f (IN) -- The function to apply to each node's content.

	Returns:	None (void).

	Notes:		If `lst` or `f` is `NULL`, the function does nothing. The 
				function iterates through the list, applying `f` to each node's 
				content. This does not modify the list structure.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

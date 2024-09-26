/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:42:53 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:43 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_lstdelone|═══════════════════════════════════════════════════════════*

	Purpose:	Deletes a single node from a linked list and applies a 
				function `del` to its content to free associated resources. 
				After calling `del`, the node itself is deallocated with `free`.
				
	Parameters:
				lst (IN) -- The node to delete.
				del (IN) -- A function to apply to the node's content to 
				            deallocate or clean up any associated resources.

	Returns:	None (void).

	Notes:		The function deletes only a single node and does not affect 
				the rest of the list. Ensure that the `del` function properly 
				frees or deallocates the content to avoid memory leaks. 
				If `lst` or `del` is `NULL`, the function does nothing.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:07:08 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:48 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_lstmap|═══════════════════════════════════════════════════════════════*

	Purpose:	Creates a new linked list by applying a given function `f` 
				to each node's content in an existing list. The new list 
				contains nodes with the transformed content.
				If memory allocation fails during the process, it uses a `del`
				function to clean up any allocated resources.
				
	Parameters:
				lst (IN) -- Pointer to the head of the original linked list.
				f (IN) -- A function to apply to each node's content in the 
				          original list, returning the transformed content.
				del (IN) -- A function to clean up the content in case 
				            memory allocation fails.

	Returns:	A pointer to the new list with the transformed content. If 
				memory allocation fails at any point, the function cleans 
				up and returns `NULL`.

	Notes:		If `lst`, `f`, or `del` is `NULL`, the function returns `NULL` 
				immediately. The `del` function must properly free or 
				deallocate the content to avoid memory leaks.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*current;

	if (!lst || !f || !del)
		return (0);
	new_list = 0;
	while (lst)
	{
		current = f(lst->content);
		new_node = ft_lstnew(current);
		if (!new_node)
		{
			del(current);
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

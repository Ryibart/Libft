/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:09:07 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:50 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_lstnew|═══════════════════════════════════════════════════════════════*

	Purpose:	Creates a new node for a linked list, initialized with the 
				given content and with the `next` pointer set to `NULL`. 
				This function is typically used to create the first node in 
				a list or to add a new node.
				
	Parameters:
				content (IN) -- The content to store in the new node.

	Returns:	A pointer to the newly created node. If memory allocation fails, 
				the function returns `NULL`.

	Notes:		The caller is responsible for managing the memory associated 
				with the list node and its content. If a new node cannot be 
				created due to memory allocation failure, ensure proper error 
				handling to avoid memory leaks.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:33:31 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/14 09:41:21 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;
	void	*temp_content;

	if (lst == NULL)
		return (NULL);
	temp_content = (*f)(lst->content);
	new_lst = ft_lstnew(temp_content);
	if (new_lst == NULL)
		return (del(temp_content), NULL);
	current = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		temp_content = (*f)(lst->content);
		current->next = ft_lstnew(temp_content);
		if (current->next == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (del(temp_content), NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (new_lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:51:30 by amantoux          #+#    #+#             */
/*   Updated: 2025/11/10 13:58:23 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (current == NULL)
		return (current);
	while (current->next != NULL)
		current = current->next;
	return (current);
}
void    ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	current = lst;
	if (current == NULL)
		return (0);
	count = 1;
	while (current->next != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	ft_lstdisplay(t_list **lst)
{
	t_list	*current;
	char   c;

	current = *lst;
	while (!current)
	{
		// ft_printf("%d", current->content);
		c = current->content + '0';
		write(1, &c, 1);
		current = current->next;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:51:30 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/12 11:11:48 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"
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

void	ft_lstadd_front(t_list **lst, t_list *new)
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

void	ft_lstdisplay(t_list **lst, char c)
{
	t_list	*current;

	current = *lst;
	ft_printf("\n");
	while (current != NULL)
	{
		// ft_printf("%d\n", current->content);
		ft_printf("%d-->", current->content);
		ft_printf("%d\n", current->index);
		current = current->next;
	}
	ft_printf("_\n");
	if (c == 'a')
		ft_printf("a\n");
	else
		ft_printf("b\n");
}

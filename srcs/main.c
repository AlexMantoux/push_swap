/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:16:16 by rtrutall          #+#    #+#             */
/*   Updated: 2026/01/19 12:45:58 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_flags	flags;

	if (argc < 2)
		return (0);
	lst_b = NULL;
	complete_lst(argv, &lst_a, &flags);
	flag_execution(flags, lst_a, lst_b);
	// ft_lstdisplay(&lst_a, 'a');
	// ft_lstdisplay(&lst_b, 'b');
	// ft_printf("______________________________\n");
	ft_lstdisplay(&lst_a, 'a');
	ft_lstdisplay(&lst_b, 'b');
	ft_printf("______________________________\n");
	normalize_indices(lst_a);
	ft_lstdisplay(&lst_a, 'a');
	ft_lstdisplay(&lst_b, 'b');
	ft_printf("______________________________\n");
}

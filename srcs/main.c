/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:44 by alexmantoux       #+#    #+#             */
/*   Updated: 2025/12/11 09:52:43 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main (int argc, char **argv)
{
    t_list  *lst_a;
    int i;

    i = 1;
    if (argc > 1)
    {
        lst_a = ft_lstnew(ft_atoi(argv[i]));
        i++;
        while (argv[i])
        {
            ft_lstadd_back(&lst_a, ft_lstnew(ft_atoi(argv[i])));
            i++;
        }
        ft_lstdisplay(&lst_a, 'a');
        swap_a(&lst_a);
    }
    return (0);
}
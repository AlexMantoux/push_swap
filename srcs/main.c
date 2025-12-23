/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:44 by alexmantoux       #+#    #+#             */
/*   Updated: 2025/12/23 12:11:28 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main (int argc, char **argv)
{
    t_list  *lst_a;
    t_list  *lst_b;
    int i;

    i = 1;
    if (argc > 1)
    {
        lst_a = ft_lstnew(ft_atoi(argv[i]));
        lst_b = NULL;
        i++;
        while (argv[i])
        {
            ft_lstadd_back(&lst_a, ft_lstnew(ft_atoi(argv[i])));
            i++;
        }
        ft_lstdisplay(&lst_a, 'a');
        ft_lstdisplay(&lst_b, 'b');
        printf("______________________________\n");
        swap_a(&lst_a);
        ft_lstdisplay(&lst_a, 'a');
        ft_lstdisplay(&lst_b, 'b');
        printf("______________________________\n");
        push_b(&lst_a, &lst_b);
        push_b(&lst_a, &lst_b);
        push_b(&lst_a, &lst_b);
        ft_lstdisplay(&lst_a, 'a');
        ft_lstdisplay(&lst_b, 'b');
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:05:44 by alexmantoux       #+#    #+#             */
/*   Updated: 2026/01/14 09:56:05 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

 int main (int argc, char **argv)
 {
    t_list  *lst_a;
    t_list  *lst_b;
    t_flags flags; 
    int i;
    double disorder;
    
    i = 1;
    if (argc > 1)
    {
        lst_a = ft_lstnew(ft_atoi(argv[i]));
        i++;
        lst_b = NULL;

        parse_flags(argc, argv, &flags);

        while (argv[i])
        {
            ft_lstadd_back(&lst_a, ft_lstnew(ft_atoi(argv[i])));
            i++;
        }

        disorder = compute_disorder(lst_a);

        if (flags.simple)
            selection_sort(&lst_a, &lst_b);
        if (flags.medium)
            ft_printf("Mode medium\n");
        if (flags.complex)
            ft_printf("Mode complex\n");
        if (flags.adaptive)
            adaptive_sort(disorder);
        if (flags.bench)
            ft_printf("Disorder: %f\n", disorder);
        
        // ft_lstdisplay(&lst_a, 'a');
        // ft_lstdisplay(&lst_b, 'b');
        // ft_printf("______________________________\n");
        ft_lstdisplay(&lst_a, 'a');
        ft_lstdisplay(&lst_b, 'b');
        ft_printf("______________________________\n");
    }
    return (0);
}
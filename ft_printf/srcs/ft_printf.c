/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:14:55 by amantoux          #+#    #+#             */
/*   Updated: 2025/11/24 10:33:12 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!c)
		return (-1);
	va_start(args, c);
	i = 0;
	count = 0;
	while (c[i])
	{
		if (c[i] == '%' && c[i + 1])
		{
			i++;
			count += handle_format(c, i, args);
		}
		else
		{
			count++;
			format_c(c[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "42 Lyon";
// 	printf("### Test de %%c ###\n\n");
// 	printf("printf retourne: %d\n", printf("printf    affiche: %c | ", 'a'));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %c | ", 'a'));
// 	printf("printf retourne: %d\n", printf("printf    affiche: %c | ", 'b'));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %c | ", 'b'));

// 	printf("\n### Test de %%s ###\n\n");
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %s | ", "Je suis cool"));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %s | ", "Je suis cool"));
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %s | ", "42 c'est cool"));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %s | ", "42 c'est cool"));
// 	// printf("printf retourne: %d\n", 
// 			// printf("printf    affiche: %s | ", NULL));
// 	// ft_printf("ft_printf retourne: %d\n", 
// 			// ft_printf("ft_printf affiche: %s | ", NULL));

// 	printf("\n### Test de %%d ###\n\n");
// 	// printf("printf retourne: %d\n", 
// 			// printf("printf    affiche: %d | ", -2147483648));
// 	// ft_printf("ft_printf retourne: %d\n", 
// 			// ft_printf("ft_printf affiche: %d | ", -2147483648));
// 	// printf("printf retourne: %d\n", 
// 		// printf("printf    affiche: %d | ", 2147483647));
// 	// ft_printf("ft_printf retourne: %d\n", 
// 		// ft_printf("ft_printf affiche: %d | ", 2147483647));
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %d | ", 865654));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %d | ", 865654));

// 	printf("\n### Test de %%i ###\n\n");
// 	// printf("printf retourne: %d\n", 
// 			// printf("printf    affiche: %i | ", -2147483648));
// 	// ft_printf("ft_printf retourne: %d\n", 
// 			// ft_printf("ft_printf affiche: %i | ", -2147483648));
// 	// printf("printf retourne: %d\n", 
// 			// printf("printf    affiche: %i | ", 2147483647));
// 	// ft_printf("ft_printf retourne: %d\n", 
// 			// ft_printf("ft_printf affiche: %i | ", 2147483647));
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %i | ", 865654));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %i | ", 865654));

// 	printf("\n### Test de %%u ###\n\n");
// 	// printf("printf retourne: %d\n", 
// 			// printf("printf    affiche: %u | ", -42));
// 	// ft_printf("ft_printf retourne: %d\n", 
// 			// ft_printf("ft_printf affiche: %u | ", -42));
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %u | ", 15));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %u | ", 15));

// 	printf("\n### Test de %%x ###\n\n");
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %x | ", 42));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %x | ", 42));
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %x | ", 15));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %x | ", 15));

// 	printf("\n### Test de %%X ###\n\n");
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %X | ", 42));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %X | ", 42));
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %X | ", 15));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %X | ", 15));

// 	printf("\n### Test de %%X ###\n\n");
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %X | ", 42));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %X | ", 42));
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %X | ", 15));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %X | ", 15));

// 	printf("\n### Test de %%p ###\n\n");
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %p | ", str));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %p | ", str));
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %p | ", NULL));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %p | ", NULL));

// 	printf("\n### Test MIX ###\n\n");
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %%, %c, %s, %d | ", 'a', "alex", 42));
// 	printf("printf retourne: %d\n", 
// 			ft_printf("printf    affiche: %%, %c, %s, %d | ", 'a', "alex", 42));
// 	printf("printf retourne: %d\n", 
// 	printf("printf    affiche: %i, %u, %x, %X, %p | ", 42, 42, 42, 42, str));
// 	printf("printf retourne: %d\n", 
// 	ft_printf("printf    affiche: %i, %u, %x, %X, %p | ", 42, 42, 42, 42, str));

// 	printf("\n### Test de conversion ###\n\n");
// 	printf("printf retourne: %d\n", 
// 			printf("printf    affiche: %c | ", 68));
// 	ft_printf("ft_printf retourne: %d\n", 
// 			ft_printf("ft_printf affiche: %c | ", 68));

// 	// printf("\n### Test du cas (null) ###\n\n");
// 	// printf("printf retourne: %d\n", printf(NULL));
// 	// ft_printf("ft_printf retourne: %d\n", ft_printf(NULL));

// 	return (0);
// }
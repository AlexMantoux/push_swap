#include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 && (result * 10 + (str[i] - '0')) < result)
			return (-1);
		if (sign == -1 && (result * 10 + (str[i] - '0')) < result)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}
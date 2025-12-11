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
  

    }
    return (0);
}
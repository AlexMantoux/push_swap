#include "../includes/push_swap.h"

int main (int argc, char **argv)
{
    t_list  *lst;
    int i;

    i = 1;
    if (argc > 1)
    {
        lst = ft_lstnew(ft_atoi(argv[i]));
        while(argv[i])
        {
            ft_lstadd_front(&lst, ft_lstnew(ft_atoi(argv[i])));
            i++;
        }

        ft_lstdisplay(&lst);
    }
    return (0);
}
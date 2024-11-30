# include <libc.h> 
# include "ft_printf.h" 

int main(void)
{
    int i;
    i = ft_printf("%p\n",&i);
    ft_printf("%i\n",i);
    i = printf("%p\n",&i);
    ft_printf("%i\n",i);
}

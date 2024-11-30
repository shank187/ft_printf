# include <libc.h> 
# include "ft_printf.h" 

int main(void)
{
    int i;
    i = ft_printf("  %s\n","hello");
    ft_printf("%i\n",i);
    i = printf("  %s\n","hello");
    ft_printf("%i\n",i);

}

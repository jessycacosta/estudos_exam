
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

//----------------------------------------------------------------

void	print_bits(unsigned char octet)
{
	int i = 8;
	int res = 0;

	while ( i--)
	{
		res = (octet >> i & 1) + '0';
		write (1, &res, 1);
	}
}

/*int main ()
{
	unsigned char octet = 9;
	print_bits(octet);
	write (1, "\n", 1);
}*/

//----------------------------------------------------------------

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	int res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int	main(void)
{
	unsigned char res = reverse_bits((unsigned char)9);
	print_bits(res);
	write (1, "\n", 1);

}

//----------------------------------------------------------------

void	ft_list_remove_if (t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *curr = *begin_list;
	t_list *remove;

	While(curr && curr->next)
	{
		if((cmp)(curr->next->data, data_ref) == 0)
		{
			remove = curr->next;
			curr->next = curr->next->next;
			free(remove);
		}
		curr = curr->next;
	}
	curr = *begin_list;
	if (curr && (cmp)(curr->data, data_ref) == 0)
	{
		*begin_list = curr->next;
		free(curr);
	}
}

//----------------------------------------------------------------

void ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *temp = lst;
	
	While(lst->next)
	{
		if(((*cmp)(lst->data, lst->next->data)) == 0)
		{
			ft_swap(&lst->data, &lst->next->data);
			lst = temp;
		}
		else
			lst = lst->next;
	}
	lst = temp;
	return (lst);
}

//----------------------------------------------------------------

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	t_list *curr = begin_list;
	
	while(curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

//----------------------------------------------------------------

void   ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *curr = begin_list;

	while(curr)
	{
		(*f)(curr->data);
		curr = curr->next;
	}
}

//----------------------------------------------------------------

//fprime

int main (int ac, char **av)
{
	if (ac == 2)
	{
		int i = 2;
		int num = atoi(av[1]);
		if (num == 1)
		{	
			printf("%d\n", 1);
			return (0);
		}
		while (num >= i)
		{
			if(num % i == 0)
			{
				printf("%d", i);				
				if(num == i)
					break;
				printf("*");
				num = num / i;
				i = 1;
			}
			i++;
		}
	}
	printf("\n");
    return (0);
}

//----------------------------------------------------------------

int len_n(int n)
{
	int i = 0;
	
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	long n = nbr;
	int len = len_n(nbr);
	char *dst = malloc(sizeof(char) * (len + 1));

	if (!dst)
		return (NULL);
	dst[len] = '\0';
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
	{
		dst[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		len--;
		dst[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (dst);
}

//----------------------------------------------------------------

void	fill(char **tab, t_point size, t_point curr, char check)
{
	if(curr.x < 0 || curr.x >= size.x || curr.y < 0 || curr.y >= size.y ||tab[curr.y][curr.x] != check)
		return;
	tab[curr.y][curr.x] = 'F';
	fill(tab, size, (t_poit){curr.x + 1, curr.y}, check);
	fill(tab, size, (t_poit){curr.x - 1, curr.y}, check);
	fill(tab, size, (t_poit){curr.x, curr.y + 1}, check);
	fill(tab, size, (t_poit){curr.x, curr.y - 1}, check);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

//----------------------------------------------------------------

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char    **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wd = 0;
	char **dst;

	while (str[i])
	{
		while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
			wd++;
		while (str[i] != 32 && str[i] != '\t'&& str[i] != '\n' && str[i] != '\0')
			i++;
	}
	dst = (char **)malloc(sizeof(char *) * (wd + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
			i++;
		j = i;
		while (str[i] != 32 && str[i] != '\t'&& str[i] != '\n' && str[i] != '\0')
			i++;
		if (i > j)
		{
			dst[k] = (char *)malloc(sizeof(char *) * (i-j + 1));
			if (!dst)
				return (NULL);
			ft_strncpy(dst[k], &str[j], i - j);
			k++;
		}
	}
	dst[k] = NULL;
	return (dst);
}

//----------------------------------------------------------------

//rev wstr
int main (int ac, char **av)
{
	int first = 1;
	int s = 0;
	int e = 0;

	if ( ac == 2)
	{
		while (av[1][e])
			e++;
		e--;
		while (e >= 0)
		{
			if (first == 0)
				write(1, " ", 1);
			first = 0;
			while (e >= 0 && (av[1][e] == 32 || av[1][e] == '\t' || av[1][e] == '\n'))
				e--;
			s = e;
			while (s >= 0 && av[1][s] != 32 && av[1][s] != '\t'&& av[1][s] != '\n' && av[1][s] != '\0')
				s--;
			write(1, &av[1][s + 1], e - s);
			e = s;			
		}			
	}
	write(1, "\n", 1);
}

//----------------------------------------------------------------

//add prime sum
int	ft_atoi(char *str)
{
	int		nbr = 0;
	
	while (*str)
		nbr = nbr * 10 + *str++ - '0';
	return (nbr);
}

int	is_prime(int nbr)
{
	int		i = 2;

	if (nbr <= 1)
		return (0);
	while (i * i <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int nbr)
{
	char	c;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

//----------------------------------------------------------------

//hipenp
void	hidenp(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s1 == *s2)
			s1++;
		s2++;
	}
	if (*s1 == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

//----------------------------------------------------------------

//lcm

unsigned int    lcm(unsigned int a, unsigned int b)
{
	int		lcm = (a >= b) ? a : b;

	if (a == 0 || b == 0)
		return (0);
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}
}

//----------------------------------------------------------------

//parasum
void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	char	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	(void)argv;
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}

//----------------------------------------------------------------

//pgcd
int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	nbr1 = atoi(argv[1]);
		int	nbr2 = atoi(argv[2]);
		int	div = 1;
		int	pgcd = 0;
		while (div <= nbr1 && div <= nbr2)
		{
			if (nbr1 % div == 0 && nbr2 % div == 0)
				pgcd = div;
			div++;
		}
		printf("%d", pgcd);
	}
	printf("\n");
	return (0);
}

//----------------------------------------------------------------

//printhex

int		ft_atoi(char *str)
{
	int		res = 0;

	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ -'0';
	return (res);
}

void	print_hex(int nbr)
{
	char	*number = "0123456789abcdef";

	if (nbr >= 16)
		print_hex(nbr / 16);
	write(1, &number[nbr % 16], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}

//----------------------------------------------------------------

int	ft_atoi(const char *str)
{
	int i = 0;
	int num = 0;
	int sig = 1;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] >= 0 && str[i] <= 9)
	{
		num = num * 10;
		num = num + str[i] - '0';
		i++;
	}
	return (num * sig);
}

//----------------------------------------------------------------

//tabmult
int	ft_atoi(char *str)
{
	int	res;

	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = n % 10 + '0';
	write (1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc == 2)
	{
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(ft_atoi(argv[1]));
			write(1, " = ", 3);
			ft_putnbr(ft_atoi(argv[1]) * i);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

//----------------------------------------------------------------

//sort in tab
void	ft_swap(int	*a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
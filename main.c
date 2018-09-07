#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
//#include "libft.h"
#define LEN 512

/*
**	FUNCTIONS PROTOTYPES
*/

void 	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
int		ft_puts(const char *s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
/*
**		partie 2
*/
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void 	ft_memset(void *b, int c, size_t len);
size_t 	ft_strlen(const char *s);
char 	*ft_strdup(const char *s1);
/*
**		partie 3
*/
void	ft_cat(int fd);
/*
**		bonus
*/
void	*ft_memrcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *restrict dst, const void *restrict src, size_t n);
int 	ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**	TESTS FUNCTIONS PROTOTYPES
*/
int 	all_test_bzero();
int		all_test_strcat();
int 	all_test_isalpha();
int 	all_test_isdigit();
int 	all_test_isalnum();
int 	all_test_isascii();
int 	all_test_toupper();
int 	all_test_tolower();
int 	all_test_isprint();
int		all_test_memcpy();
int		all_test_memrcpy();
int		all_test_memmove();
int		all_test_memset();
int 	all_test_strlen();
int		all_test_memcmp();


int main(void)
{
	int fd;
	unsigned int nb_error;
	nb_error = 0;
	nb_error += all_test_bzero();
	nb_error += all_test_strcat();
	nb_error += all_test_isalpha();
	nb_error += all_test_isdigit();
	nb_error += all_test_isalnum();
	nb_error += all_test_isascii();
	nb_error += all_test_isprint();
	nb_error += all_test_toupper();
	nb_error += all_test_tolower();
	nb_error += all_test_strlen();
	nb_error += all_test_memset();
	nb_error += all_test_memrcpy();
	nb_error += all_test_memcpy();
	//nb_error += all_test_memmove();
	nb_error += all_test_strlen();
	nb_error += all_test_memcmp();
	//char buffer1[] = "\200";
	//char buffer2[] = "\0";
	//printf("ret ft_memcmp:0x%02x %d\n",ft_memcmp(buffer1, buffer2, strlen(buffer1))
	//								,ft_memcmp(buffer1, buffer2, strlen(buffer1)));
	//printf("ret memcmp:0x%02x %d\n",memcmp(buffer1, buffer2, strlen(buffer1))
	//								,memcmp(buffer1, buffer2, strlen(buffer1)));
	//ft_cat(0);
	printf("errror detected:%d\n", nb_error);
	
  return 0;
}

/*
** BZERO TESTS
*/
static int	test_bzero(char *buff1, char *buff2, size_t len)
{
	bzero(buff1, len);
	ft_bzero(buff2, len);
	printf("len=%zu =>\t", len);
	if (!memcmp(buff1, buff2, len))
		printf("\e[0;32mOK\e[0;0m\n");
	else
	{
		printf("\e[0;31mKO\e[0;0m\n");
		int i;
		for (i = 0; i < len; ++i)
			printf("buf[i]:0x%02x\n", buff2[i]);
		return (1);
	}
	return (0);
}

int			all_test_bzero()
{
	printf("\e[0;33mLAUNCH TEST BZERO\e[0;0m\n");
	char buff1[LEN];
	char buff2[LEN];
	int len[] = {1, 20, 40};
	int i;
	unsigned int error;

	for (i = 0; i < 3 ; i++)
		error = test_bzero(buff1, buff2, len[i]);

	return (error);	
}

/*
** STRCAT TESTS
*/
static int	test_strcat(char *buff1, char *buff2, char *val1, char *val2)
{
	printf("val1:%s\tval2:%s\t", val1, val2);
	strcpy(buff1, val1);
	strcpy(buff2, val1);
	strcat(buff1, val2);
	ft_strcat(buff2, val2);
	if (!strcmp(buff1, buff2))
		printf("\e[0;32mOK\e[0;0m\n");
	else
		printf("\e[0;31mKO\e[0;0m\n");
	return (0);
}

int			all_test_strcat()
{
	printf("\e[0;33mLAUNCH TEST STRCAT\e[0;0m\n");
	char buff1[256];
	char buff2[256];

	char *value[][512] = {
		{"Toto", " et titi"},
		{"Toto", " yo"},
		{"Toto", ""},
		{"", "Toto"},
		{"", ""},
		0
	};
	int i;
	while (value[i][0])
	{
		test_strcat(buff1, buff2, value[i][0], value[i][1]);
		++i;
	}
	return (0);
}

/*
** ISALPHA TESTS
*/
int 		all_test_isalpha()
{
	printf("\e[0;33mLAUNCH TEST ISALPHA\e[0;0m\n");
	char	val[129] = { 0x00, 0x01, 0x02, 0x03
						, 0x04, 0x05, 0x06, 0x07
						, 0x08, 0x09, 0x0a, 0x0b
						, 0x0c, 0x0d, 0x0e, 0x0f
						, 0x10, 0x11, 0x12, 0x13
						, 0x14, 0x15, 0x16, 0x17
						, 0x18, 0x19, 0x1a, 0x1b
						, 0x1c, 0x1d, 0x1e, 0x1f
						, 0x20, 0x21, 0x22, 0x23
						, 0x24, 0x25, 0x26, 0x27
						, 0x28, 0x29, 0x2a, 0x2b
						, 0x2c, 0x2d, 0x2e, 0x2f
						, 0x30, 0x31, 0x32, 0x33
						, 0x34, 0x35, 0x36, 0x37
						, 0x38, 0x39, 0x3a, 0x3b
						, 0x3c, 0x3d, 0x3e, 0x3f
						, 0x40, 0x41, 0x42, 0x43
						, 0x44, 0x45, 0x46, 0x47
						, 0x48, 0x49, 0x4a, 0x4b
						, 0x4c, 0x4d, 0x4e, 0x4f
						, 0x50, 0x51, 0x52, 0x53
						, 0x54, 0x55, 0x56, 0x57
						, 0x58, 0x59, 0x5a, 0x5b
						, 0x5c, 0x5d, 0x5e, 0x5f
						, 0x60, 0x61, 0x62, 0x63
						, 0x64, 0x65, 0x66, 0x67
						, 0x68, 0x69, 0x6a, 0x6b
						, 0x6c, 0x6d, 0x6e, 0x6f
						, 0x70, 0x71, 0x72, 0x73
						, 0x74, 0x75, 0x76, 0x77
						, 0x78, 0x79, 0x7a, 0x7b
						, 0x7c, 0x7d, 0x7e, 0x7f
						, 0xff};
	int		ret1;
	int		ret2;
	int 	i;
	unsigned int error;

	error = 0;
	for (i = 0; i < 129; i++)
	{
		printf("test_%d: value=0x%02x =>\t", i, val[i]);
		if (isalpha(val[i]) != ft_isalpha(val[i]))
		{
			++error;
			printf("\e[0;31mKO\n\e[0;0m");
		}
		else
			printf("\e[0;32mOK\n\e[0;0m");
	}
	return (error);
}

/*
** ISALPHA TESTS
*/
int 		all_test_isdigit()
{
	printf("\e[0;33mLAUNCH TEST ISDIGIT\e[0;0m\n");
	int		ret1;
	int		ret2;
	int 	i;
	unsigned int error;

	error = 0;
	for (i = -1; i < 129; i++)
	{
		printf("test_%d: value=0x%02x =>\t", i, i);
		if (isdigit(i) != ft_isdigit(i))
		{
			++error;
			printf("\e[0;31mKO\n\e[0;0m");
		}
		else
			printf("\e[0;32mOK\n\e[0;0m");
	}
	return (error);
}

/*
** ISALNUM TESTS
*/
int 		all_test_isalnum()
{
	printf("\e[0;33mLAUNCH TEST ISALNUM\e[0;0m\n");
	int		ret1;
	int		ret2;
	int 	i;
	unsigned int error;

	error = 0;
	for (i = -1; i < 129; i++)
	{
		printf("test_%d: value=0x%02x =>\t", i, i);
		if (isalnum(i) != ft_isalnum(i))
		{
			++error;
			printf("\e[0;31mKO\n\e[0;0m");
		}
		else
			printf("\e[0;32mOK\n\e[0;0m");
	}
	return (error);
}

/*
** ISASCII TESTS
*/
int 		all_test_isascii()
{
	printf("\e[0;33mLAUNCH TEST ISASCII\e[0;0m\n");
	int		ret1;
	int		ret2;
	int 	i;
	unsigned int error;

	error = 0;
	for (i = -1; i < 200; i++)
	{
		printf("test_%d: value=0x%02x =>\t", i, i);
		if (isascii(i) != ft_isascii(i))
		{
			++error;
			printf("\e[0;31mKO\n\e[0;0m");
		}
		else
			printf("\e[0;32mOK\n\e[0;0m");
	}
	return (error);
}

/*
** ISPRINT TESTS
*/
int 		all_test_isprint()
{
	printf("\e[0;33mLAUNCH TEST ISPRINT\e[0;0m\n");
	int		ret1;
	int		ret2;
	int 	i;
	unsigned int error;

	error = 0;
	for (i = -1; i < 200; i++)
	{
		printf("test_%d: value=0x%02x =>\t", i, i);
		if (isprint(i) != ft_isprint(i))
		{
			++error;
			printf("\e[0;31mKO\n\e[0;0m");
		}
		else
			printf("\e[0;32mOK\n\e[0;0m");
	}
	return (error);
}

/*
** TOUPPER TESTS
*/
int 		all_test_toupper()
{
	printf("\e[0;33mLAUNCH TEST TOUPPER\e[0;0m\n");
	int 	i;
	unsigned int error;

	error = 0;
	for (i = -1; i < 200; i++)
	{
		printf("test_%d: value=0x%02x =>\t", i, i);
		if (toupper(i) != ft_toupper(i))
		{
			++error;
			printf("\e[0;31mKO\n\e[0;0m");
		}
		else
			printf("\e[0;32mOK\n\e[0;0m");
	}
	return (error);
}

/*
** TOLOWER TESTS
*/
int 		all_test_tolower()
{
	printf("\e[0;33mLAUNCH TEST TOLOWER\e[0;0m\n");
	int 	i;
	unsigned int error;

	error = 0;
	for (i = -1; i < 200; i++)
	{
		printf("test_%d: value=0x%02x =>\t", i, i);
		if (tolower(i) != ft_tolower(i))
		{
			++error;
			printf("\e[0;31mKO\n\e[0;0m");
		}
		else
			printf("\e[0;32mOK\n\e[0;0m");
	}
	return (error);
}

/*
** STRLEN TESTS
*/
static int 	test_strlen(char *str)
{
	int ret1, ret2;

	ret1 = strlen(str);
	ret2 = ft_strlen(str);
	printf("string:%s =>\t", str);
	if (ret1 == ret2)
	{
		printf("\e[0;32mOK\e[0;0m\n");
		return (0);
	}
	else
	{
		printf("\e[0;31mKO\e[0;0m\n");
		return (1);
	}
}
int 		all_test_strlen()
{
	unsigned int error;

	error = 0;
	printf("\e[0;33mLAUNCH TEST STRLEN\e[0;0m\n");
	error += test_strlen("Hello world\n");
	error += test_strlen("");
	return (error);
}

/*
** MEMSET TESTS
*/
static int	test_memset(char *buff1, char *buff2, int val, size_t len)
{
	printf("int val=0x%02x\tlen=%zd =>\t", val, len);
	memset(buff1, val, len);
	ft_memset(buff2, val, len);
	if (!memcmp(buff1, buff2, len))
		printf("\e[0;32mOK\e[0;0m\n");
	else
	{
		printf("\e[0;31mKO\e[0;0m\n");
		int i;
		for (i = 0; i < len; ++i)
			printf("buf[i]:0x%02x\n", buff2[i]);
		return (1);
	}
	return (0);
}
int			all_test_memset()
{
	printf("\e[0;33mLAUNCH TEST MEMSET\e[0;0m\n");
	char buff1[LEN];
	char buff2[LEN];
	unsigned int error;
	struct s_memset { int val; int len;};
	static struct s_memset data_memset[] = {
	 {'A', 20}, 
	 {'B', 50}, 
	 {1, 10},
	};
	int i;

	error = 0; 
	for (i = 0; i < 3 ; i++)
		error += test_memset(buff1, buff2, data_memset[i].val, data_memset[i].len);	
	return (error);
}

/*
** MEMCPY TESTS
*/
static int	test_memcpy(char *buff1, char *buff2, char *val, int len)
{
	printf("val=%s\tlen=%d\t", val, len);
	memcpy(buff1, val, len);
	ft_memcpy(buff2, val, len);
	if (!memcmp(buff1, buff2, len))
	{
		printf("\e[0;32mOK\e[0;0m\n");
		return (0);
	}
	else
	{
		printf("\e[0;31mKO\e[0;0m\n");
		return (1);
	}
}
int			all_test_memcpy()
{
	printf("\e[0;33mLAUNCH TEST MEMCPY\e[0;0m\n");
	char buff1[256];
	char buff2[256];
	int error = 0;

	static char *val_memcpy[] = {
		"Toto",
		"Titi",
		"",
		0
	};
	int i;
	while (val_memcpy[i])
	{
		error += test_memcpy(buff1, buff2, val_memcpy[i], strlen(val_memcpy[i]));
		++i;
	}
	return (error);
}

/*
** MEMRCPY TESTS
*/
static int	test_memrcpy(char *buff1, char *buff2, char *val, int len)
{
	printf("val=%s\tlen=%d\t", val, len);
	memcpy(buff1, val, len);
	ft_memrcpy(buff2, val, len);
	if (!memcmp(buff1, buff2, len))
	{
		printf("\e[0;32mOK\e[0;0m\n");
		return (0);
	}
	else
	{
		printf("\e[0;31mKO\e[0;0m\n");
		return (1);
	}
}
int			all_test_memrcpy()
{
	printf("\e[0;33mLAUNCH TEST MEMRCPY\e[0;0m\n");
	char buff1[256];
	char buff2[256];
	int error = 0;

	char *val_memrcpy[] = {
		"Toto",
		"Titi",
		"",
		0
	};
	int i;
	while (val_memrcpy[i])
	{
		error += test_memrcpy(buff1, buff2, val_memrcpy[i], strlen(val_memrcpy[i]));
		++i;
	}
	return (error);
}

/*
** MEMMOVE TESTS
*/
static int	test_memmove(char *buff1, char *buff2, char *val, int len)
{
	printf("val=%s\tlen=%d\t", val, len);
	memmove(buff1, val, len);
	ft_memmove(buff2, val, len);
	if (!memcmp(buff1, buff2, len))
	{
		printf("\e[0;32mOK\e[0;0m\n");
		return (0);
	}
	else
	{
		printf("\e[0;31mKO\e[0;0m\n");
		return (1);
	}
}
int			all_test_memmove()
{
	printf("\e[0;33mLAUNCH TEST MEMMOVE\e[0;0m\n");
	char buff1[256];
	char buff2[256];
	int error = 0;

	char *val_memmove[] = {
		"Toto",
		"Titi",
		"",
		0
	};
	int i;
	while (val_memmove[i])
	{
		error += test_memmove(buff1, buff2, val_memmove[i], strlen(val_memmove[i]));
		++i;
	}
	return (error);
}

/*
** MEMMOVE TESTS
*/
static int	test_memcmp(char *buff1, char *buff2, char *val1, char *val2, int len)
{
	int ret1;
	int ret2;
	int len2;

	len2 = 0;
	printf("val=%s\tlen=%d\t", val1, len);
	if (val2)
	{
		len2 = strlen(val2);
		printf("\nval2=%s\tlen=%d\t", val2, len2);
	}

	strcpy(buff1, val1);
	if (val2)
		strcpy(buff2, val2);
	else
		strcpy(buff2, val1);
	
	ret1 = memcmp(buff1, buff2, len < len2 ? len : len2);
	ret2 = ft_memcmp(buff1, buff2, len < len2 ? len : len2);
	if (ret1 == ret2)
	{
		printf("\e[0;32mOK\e[0;0m\n");
		return (0);
	}
	else
	{
		printf("\e[0;31mKO\e[0;0m real:%d your:%d\n", ret1, ret2);
		return (1);
	}
}
int			all_test_memcmp()
{
	printf("\e[0;33mLAUNCH TEST MEMCMP\e[0;0m\n");
	char buff1[256];
	char buff2[256];
	int error = 0;

	char *val_memcmp[] = {
		"Ecole 42\0"
		"\200",
		"\0",
		"",
		0
	};
	int i = 0;
	while (val_memcmp[i])
	{
		error += test_memcmp(buff1, buff2, val_memcmp[i], 0, strlen(val_memcmp[i]));
		++i;
	}

	error += test_memcmp(buff1, buff2, "Toto", "Tat", 4);
	error += test_memcmp(buff1, buff2, "\200", "\0", 4);
	error += test_memcmp(buff1, buff2, "\0", "\200", 4);
	return (error);
}

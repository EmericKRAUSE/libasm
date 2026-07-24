#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);

int main() {
    // ft_strlen
    {
        const char* str1 = "Hello World";
        const char* str2 = "";

        printf("strlen: %lu\n", strlen(str1));
        printf("ft_strlen: %lu\n", ft_strlen(str1));
        printf("strlen: %lu\n", strlen(str2));
        printf("ft_strlen: %lu\n", ft_strlen(str2));
    }
    // ft_strcpy
    {
        const char* str1 = "Hello World";
        char* str2;

        str2 = malloc(sizeof(char) * (strlen(str1) + 1));
        if (!str2)
            return (1);

        printf("strcpy: %s\n", strcpy(str2, str1));
        printf("ft_strcpy: %s\n", ft_strcpy(str2, str1));

        free(str2);
    }

    return(0);
}
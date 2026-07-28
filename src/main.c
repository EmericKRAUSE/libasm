#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include "../includes/colors.h"

// Prototypes des fonctions
size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char    *ft_strdup(const char *s);

int main(void) {

    /* -------------------------------------------------------------------- */
    /* 1. FT_STRLEN                                                         */
    /* -------------------------------------------------------------------- */
    printf(CYAN "=== 1. TEST FT_STRLEN ===\n" RESET);
    {
        const char *str = "Hello World!";
        size_t res_sys = strlen(str);
        size_t res_mine = ft_strlen(str);

        printf("Chaine  : \"%s\"\n", str);
        printf("Vrai    : %lu\n", res_sys);
        printf("Libasm  : %lu -> [%s]\n\n", res_mine, 
               (res_sys == res_mine) ? GREEN "OK" RESET : RED "KO" RESET);
    }

    /* -------------------------------------------------------------------- */
    /* 2. FT_STRCPY                                                         */
    /* -------------------------------------------------------------------- */
    printf(CYAN "=== 2. TEST FT_STRCPY ===\n" RESET);
    {
        const char *src = "Copie moi !";
        char dest_sys[50];
        char dest_mine[50];

        strcpy(dest_sys, src);
        ft_strcpy(dest_mine, src);

        printf("Source  : \"%s\"\n", src);
        printf("Vrai    : \"%s\"\n", dest_sys);
        printf("Libasm  : \"%s\" -> [%s]\n\n", dest_mine, 
               (strcmp(dest_sys, dest_mine) == 0) ? GREEN "OK" RESET : RED "KO" RESET);
    }

    /* -------------------------------------------------------------------- */
    /* 3. FT_STRCMP                                                         */
    /* -------------------------------------------------------------------- */
    printf(CYAN "=== 3. TEST FT_STRCMP ===\n" RESET);
    {
        const char *s1 = "AAA";
        const char *s2 = "BBB";

        int res_sys = strcmp(s1, s2);
        int res_mine = ft_strcmp(s1, s2);

        // On verifie si les deux renvoient le meme signe (negatif dans ce cas)
        int same_sign = (res_sys < 0 && res_mine < 0) || (res_sys > 0 && res_mine > 0) || (res_sys == res_mine);

        printf("Compare : \"%s\" et \"%s\"\n", s1, s2);
        printf("Vrai    : %d\n", res_sys);
        printf("Libasm  : %d -> [%s]\n\n", res_mine, 
               same_sign ? GREEN "OK" RESET : RED "KO" RESET);
    }

    /* -------------------------------------------------------------------- */
    /* 4. FT_WRITE                                                          */
    /* -------------------------------------------------------------------- */
    printf(CYAN "=== 4. TEST FT_WRITE ===\n" RESET);
    {
        // --- Test de sortie normale ---
        printf("Ecriture sur l'ecran (stdout) :\n");
        printf("Vrai    : "); fflush(stdout);
        ssize_t ret_sys = write(1, "Hello\n", 6);

        printf("Libasm  : "); fflush(stdout);
        ssize_t ret_mine = ft_write(1, "Hello\n", 6);
        printf("Retour write -> Vrai: %ld | Libasm: %ld\n\n", ret_sys, ret_mine);

        // --- Test de gestion d'erreur (mauvais FD) ---
        errno = 0;
        ret_sys = write(-1, "test", 4);
        int err_sys = errno;

        errno = 0;
        ret_mine = ft_write(-1, "test", 4);
        int err_mine = errno;

        printf("Test d'erreur (fd invalide = -1) :\n");
        printf("Vrai    : ret = %ld, errno = %d\n", ret_sys, err_sys);
        printf("Libasm  : ret = %ld, errno = %d -> [%s]\n\n", ret_mine, err_mine,
               (ret_sys == ret_mine && err_sys == err_mine) ? GREEN "OK" RESET : RED "KO" RESET);
    }

    /* -------------------------------------------------------------------- */
    /* 5. TEST FT_READ                                                      */
    /* -------------------------------------------------------------------- */
    printf(CYAN "=== 5. TEST FT_READ ===\n" RESET);
    {
        char buf_sys[50] = {0};
        char buf_mine[50] = {0};

        // --- Test d'erreur simple ---
        errno = 0;
        ssize_t ret_sys = read(-1, buf_sys, 10);
        int err_sys = errno;

        errno = 0;
        ssize_t ret_mine = ft_read(-1, buf_mine, 10);
        int err_mine = errno;

        printf("Test d'erreur (fd invalide = -1) :\n");
        printf("Vrai    : ret = %ld, errno = %d\n", ret_sys, err_sys);
        printf("Libasm  : ret = %ld, errno = %d -> [%s]\n\n", ret_mine, err_mine,
               (ret_sys == ret_mine && err_sys == err_mine) ? GREEN "OK" RESET : RED "KO" RESET);
    }

    /* -------------------------------------------------------------------- */
    /* 6. FT_STRDUP                                                         */
    /* -------------------------------------------------------------------- */
    printf(CYAN "=== 6. TEST FT_STRDUP ===\n" RESET);
    {
        const char *str = "Chaine a dupliquer avec malloc";

        char *sys_dup = strdup(str);
        char *mine_dup = ft_strdup(str);

        printf("Original: \"%s\"\n", str);
        printf("Vrai    : \"%s\"\n", sys_dup);
        printf("Libasm  : \"%s\" -> [%s]\n", mine_dup, 
               (strcmp(sys_dup, mine_dup) == 0) ? GREEN "OK" RESET : RED "KO" RESET);

        free(sys_dup);
        free(mine_dup);
    }

    return (0);
}
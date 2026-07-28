#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../includes/colors.h"

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);

int main() {
    printf(CYAN "=== TEST FT_STRLEN ===\n" RESET);
    {
        const char *tests[] = {
            "Hello World",
            "",
            "a",
            "Un long texte pour tester si la boucle rcx ne plante pas...",
            NULL
        };

        for (int i = 0; tests[i] != NULL; i++) {
            size_t sys = strlen(tests[i]);
            size_t mine = ft_strlen(tests[i]);
            printf("[%s] sys: %lu, mine: %lu -> [%s]\n",
                tests[i],
                sys,
                mine,
                sys == mine ? GREEN "OK" RESET: RED "KO" RESET);
        }
    }

    printf(CYAN "\n=== TEST FT_STRCPY ===\n" RESET);
    {
        const char *srcs[] = {
            "Hello World",
            "",
            "Un deux trois 123456789",
            NULL
        };

        for (int i = 0; srcs[i] != NULL; i++) {
            char sys_dest[100];
            char mine_dest[100];

            strcpy(sys_dest, srcs[i]);
            char *ret = ft_strcpy(mine_dest, srcs[i]);

            int ok = (strcmp(sys_dest, mine_dest) == 0) && (ret == mine_dest);

            printf("[%s] sys: %s, mine: %s -> [%s]\n",
                srcs[i],
                sys_dest,
                mine_dest,
                ok ? GREEN "OK" RESET : RED "KO" RESET);
        }
    }

    printf(CYAN "\n=== TEST FT_STRCMP ===\n" RESET);
    {
        struct {
            const char *s1;
            const char *s2;
        } tests[] = {
            {"Hello world", "Hello you"},      // s1 < s2
            {"Hello you", "Hello world"},      // s1 > s2
            {"Hello world", "Hello world"},    // s1 == s2
            {"", ""},                          // Chaines vides
            {"Hello", ""},                     // Chaine vide en s2
            {"", "Hello"},                     // Chaine vide en s1
            {"ABC", "AB"},                     // Longueurs differentes
            {"\xff", "\x01"},                  // Test de l'unsigned char (tres important !)
            {NULL, NULL}
        };

        for (int i = 0; tests[i].s1 != NULL; i++) {
            int sys = strcmp(tests[i].s1, tests[i].s2);
            int mine = ft_strcmp(tests[i].s1, tests[i].s2);

            // On verifie si le signe est identique (car la libc peut renvoyer n'importe quel entier negatif/positif)
            int ok = (sys == mine) || (sys < 0 && mine < 0) || (sys > 0 && mine > 0);

            printf("[%s] vs [%s] -> Libc: %d | Mine: %d [%s]\n", 
                tests[i].s1, tests[i].s2, sys, mine, ok ? "OK" : "KO");
        }
    }

    return (0);
}
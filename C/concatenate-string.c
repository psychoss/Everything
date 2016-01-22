#include <ctime>
#include <cstdio>
#include <cstring>
#include <string>

void a(char *first, char *second, char *both) {
    for (int i = 0; i != 1000000; i++) {
        strcpy(both, first);
        strcat(both, " ");
        strcat(both, second);
    }
}

void b(char *first, char *second, char *both) {
    for (int i = 0; i != 1000000; i++)
        sprintf(both, "%s %s", first, second);
}

void c(char *first, char *second, char *both) {
    std::string first_s(first);
    std::string second_s(second);
    std::string both_s(second);

    for (int i = 0; i != 1000000; i++)
        both_s = first_s + " " + second_s;
}

int main(void) {
    char *first = "First";
    char *second = "Second";
    char *both = (char *) malloc((strlen(first) + strlen(second) + 2) * sizeof(char));
    clock_t start;

    start = clock();
    a(first, second, both);
    printf("C string handling = %f seconds\n", (float) (clock() - start) / CLOCKS_PER_SEC);

    start = clock();
    b(first, second, both);
    printf("sprintf           = %f seconds\n", (float) (clock() - start) / CLOCKS_PER_SEC);

    start = clock();
    c(first, second, both);
    printf("std::string       = %f seconds\n", (float) (clock() - start) / CLOCKS_PER_SEC);

    return 0;
}
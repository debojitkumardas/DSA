#include <stdio.h>
#include <stdlib.h>

char error_mode;
FILE* error_log;

#define StopIf(assertion, error_action, ...) {                      \
        if (assertion) {                                            \
            fprintf(error_log ? error_log : stderr, __VA_ARGS__);   \
            fprintf(error_log ? error_log : stderr, "\n");          \
            if (error_mode == 's')  abort();                        \
            else                    {error_action;}                 \
        }                                                           \
}

int main(void) {

    double x = 4;

    StopIf(x < 0 || x > 1, return -1, "x has value %g, "
           "but is should be between zero and one.", x);

    return 0;
}

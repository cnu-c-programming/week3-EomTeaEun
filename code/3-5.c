#include <stdio.h>
#include <stdarg.h>

void my_sum(char type, int count, ...) {
    va_list args;
    va_start(args, count); 

    int total_sum = 0;

    for (int i = 0; i < count; i++) {
        if (type == 'S') {
            char* s = va_arg(args, char*);
            printf("%s", s);
        } 
        else if (type == 'C') {
            char c = (char)va_arg(args, int);
            printf("%c", c);
        } 
        else if (type == 'D') {
            total_sum += va_arg(args, int);
        }
    }

    if (type == 'D') {
        printf("%d", total_sum);
    }
    printf("\n"); 

    va_end(args); 
}

int main() {
    my_sum('S',2,"Hello","World");
    my_sum('C',3,'C','N','U');
    my_sum('D',4,10,20,30,40);
    return 0;
}
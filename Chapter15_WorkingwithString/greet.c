#include <stdio.h>
#include <ctype.h>

int main(){
    char greeting[] = "hello, world!\n";
    printf("%s", greeting);

    int i = 0;
    while (greeting[i] != '\0') {
        greeting[i] = toupper(greeting[i]);
        i++;
    }
    printf("%s", greeting);
    return 0;
}

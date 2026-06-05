#include <stdio.h>

int main(){
    char weekdays[][10] = {
        "Sunday",
        "Monday",
        "Tuesday"
    };
    int i;
    while (weekdays[0][i] != '\0') {
        char str[] = "daysun";
        weekdays[0][i] = str[i];        // This code reads the array one element at a time and writes the values to `weekdays[0]` one by one.
        i++;
    }

    printf("%s", weekdays[0]);
}

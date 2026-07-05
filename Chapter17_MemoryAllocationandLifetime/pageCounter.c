#include <stdio.h>

void printPage(const char* aHeading);

int main(){
    printPage("Title Page");
    printPage("Chapter 1");
    printPage("         ");
    printPage("Chapter 2");
    printPage("Conclusion");
}

void printPage(const char* aHeading){
    static int pageNo = 1;        // We need a static variable because the pageNo function can be countable every time it is called.

    printf( "---------------------\n"
            "| %10s        |\n" , aHeading );

    printf( "|                   |\n"
            "|    Page Content   |\n"
            "|     Goes Here     |\n"
            "|                   |\n");

    printf( "|            Page %1d |\n"
            "---------------------\n" , pageNo );
    pageNo++;
}

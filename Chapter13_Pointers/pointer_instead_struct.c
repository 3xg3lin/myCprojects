#include <stdio.h>

typedef struct _RectDimension{
    double height;
    double width;
    double perimeter;
} RecDimension;

RecDimension RectPerimeter(RecDimension rd){
    rd.height += 10.0;
    rd.width += 10.0;
    rd.perimeter = 2*(rd.height*rd.width);
    return rd;
}

int main(){
    RecDimension rd;
    rd.height = 15.0;
    rd.width = 22.5;
    rd = RectPerimeter(rd);
    printf("rd.height = %lg, rd.width = %lg, rd.perimeter = %lg\n", rd.height, rd.width, rd.perimeter);
    return 0;
}

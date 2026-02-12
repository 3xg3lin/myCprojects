#include <stdio.h>

enum shape {
    triangle,
    square,
    rectangle,
    trapezoid,
    pentagon,
    hexagon,
    octagon,
    circle
};

void PrintShapeInfo(enum shape aShape);
const char* GetShapeName(enum shape aShape);

int main() {
    PrintShapeInfo( triangle );
    PrintShapeInfo( square );
    PrintShapeInfo( rectangle );
    PrintShapeInfo( trapezoid );
    PrintShapeInfo( pentagon );
    PrintShapeInfo( hexagon );
    PrintShapeInfo( octagon );
    PrintShapeInfo( circle );
    return 0;
}

void PrintShapeInfo(enum shape aShape){
    int nSides = 0;
    switch (aShape) {
        case triangle:
            nSides = 3;
            break;
        case square:
        case rectangle:
        case trapezoid:
            nSides = 4;
            break;
        case circle:
            printf( "A circle has an infinite number of sides\n" );
            return;
            break;
        default:
            printf("UNKNOWN SHAPE TYPE\n");
            return;
            break;
    }
    printf( "A %s has %d sides\n" , GetShapeName( aShape) , nSides );
}

const char* GetShapeName(enum shape aShape){
    const char *name;
    switch (aShape) {
        case triangle:  name = "triangle";  break;
        case square:    name = "square";    break;
        case rectangle: name = "rectangle"; break;
        case trapezoid: name = "trapezoid"; break;
        case pentagon:  name = "pentagon";  break;
        case hexagon:   name = "hexagon";   break;
        case octagon:   name = "octagon";   break;
        case circle:    name = "circle";    break;
        default:        name = "unknown";   break;
    }
    return name;
}

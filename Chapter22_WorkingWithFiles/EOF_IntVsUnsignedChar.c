#include <stdio.h>

int main(){
    unsigned char uc = 255;    // -1
    signed char sc = -1;       // -1
    char c = -1;               //  ? (implementation dependent)

    signed int unsignedch = uc;   // unsigned char (-1) converted to int:
                                  //   unsigned bit pattern persevered in wider int size.
                                  //
    signed int signedch = sc;     // signed char (-1) converted to int
                                  //   signed-ness extended from byte to wider int size.
                                  //
    signed int plainch = c;       // plain char (-1) converted to 1nt
                                  //   IMPLEMENTATION DEPENDENT: you need to verify.
                                  //
    printf("unsigned char is %2lu bytes\n", sizeof(unsigned char));
    printf("signed char is %2lu bytes\n", sizeof(signed char));
    printf("plain char is %2lu byte\n", sizeof(char));
    printf("unsigned int is %2lu bytes\n", sizeof(unsigned int));
    printf("signed int is %2lu bytes\n\n", sizeof(signed int));

    // (signed char)uc reinterprets uc's bit pattern (0xFF) under signed rules:
    //   same bits, but now read as -1 instead of 255.
    // When promoted to int for %d, that -1 is sign-extended (not zero-extended),
    // so the int keeps the value -1 all the way through.
    // Result: %d prints -1, even though uc itself still holds 255.
    printf("unsigned char uc (-1) as unsigned int is [%d] but if cast unsigned char the result is [%d] \n", unsignedch, (signed char)uc);
    printf("signed char sc (-1) as signed int is [%d]\n", signedch);
    printf("plain char  c (-1) as signed int is [%d]\n\n", plainch);
    printf("(constant) EOF is %d\n\n", EOF);

    uc = EOF;    // converts -1 to 255.
    // --------------------------------------------------------------------
    // int (-1) -> unsigned char conversion.
    //
    // KEY POINT: this modulo rule applies specifically because the
    // TARGET type is unsigned. That is the trigger condition — any time
    // you convert a value into an unsigned type and it doesn't fit in
    // that type's range, the C standard guarantees this exact rule:
    //
    //     result = value mod 2^N      (N = bit width of the unsigned target)
    //
    // Here: target is unsigned char (N = 8), value is -1:
    //     -1 mod 256 = 255
    // so uc becomes 255 (same value it started with).
    //
    // This is guaranteed by the standard regardless of HOW the conversion
    // happens — explicit cast (unsigned char)EOF or implicit assignment
    // like this one both invoke the same rule, because what matters is
    // only the target type being unsigned, not the syntax used to convert.
    // --------------------------------------------------------------------
}

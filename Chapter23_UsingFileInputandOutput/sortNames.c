#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>       // for getopt
#include <sys/errno.h>    // for errno
#include "nameList.h"

enum{
    kStringMax = 80
};

void usage(char* cmd);
int  getName(FILE* inFileDesc, char* pStr);
void putName(char* pStr, FILE* outFileDesc);
int trimStr(char* pStr);

int main(int argc, char* argv[]){
    int ch;
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;

    // parse command line options
    while ((ch = getopt(argc, argv, "i:o:h?")) != -1) {
        switch (ch) {
            case 'i':
                // try to open input file for reading
                if (NULL == (inputFile = fopen(optarg, "r"))) {
                    fprintf(stderr, "inputFile \"%s\": %s\n", optarg, strerror(errno));
                    exit(EXIT_FAILURE);
                }
                fprintf(stderr, "Using\"%s\" for input.\n", optarg);
                break;
            case 'o':
                // try to open output file for appending
                if (NULL == (outputFile = fopen(optarg, "w"))) {
                    fprintf(stderr, "output file \"%s\": %s \n", optarg, strerror(errno));
                    exit(EXIT_FAILURE);
                }
                fprintf(stderr, "Using\"%s\" for output.\n", optarg);
                break;
            case '?':
            case 'h':
            default:
                // show usage and exit on bad or help flag
                usage(argv[0]);
                break;
        }
    }

    // fall back to stdin if no input file given
    if (!inputFile){
        inputFile = stdin;
        fprintf(stderr, "Using stdin for input.\n");
    }
    // fall back to stdout if no output file given
    if (!outputFile) {
        outputFile = stdout;
        fprintf(stderr, "Using stdout for output\n");
    }

    char nameBuffer[kStringMax];
    NameList nameList = {0};

    while (getName(inputFile, nameBuffer)) {
        AddName(&nameList, nameBuffer);
    }
    PrintNames(outputFile, &nameList);
    DeleteNames(&nameList);

    fprintf(stderr, "Closing files.\n");
    fclose(inputFile);
    fflush(outputFile);
    fclose(outputFile);
    fprintf(stderr, "Done.\n");
    return 0;
}

void usage(char* cmd){
    fprintf(stderr, "usage: %s [-i inputFileName] [-o outputFileName]\n", cmd);
    fprintf(stderr, "If -i inputFileName is not given," " stdin is used.\n");
    fprintf(stderr, "If -o outputFName is not given," " stdout is used.\n\n");
    exit(EXIT_SUCCESS);
}

// getName -- Read nameString (a full line)
//            If input is from stdin, give prompt.
//            Trim excess whitespace before and after string
//            (including <newline> which fgets() preserves).
//  parameters:
//    inFileDesc - input stream
//    nameStr    - array of characters allocated by caller
//  returns:
//    length of nameStr. 0, or empty string, means end of input.
//

int getName(FILE* inFileDesc, char* pStr){
    static int numNames = 0;
    int len;

    memset(pStr, 0, kStringMax);   // clear buffer first

    // only prompt when reading from stdin
    if (stdin == inFileDesc) {
        fprintf(stdout, "Name %d: ", numNames+1);
    }

    // In this use of fgets(), we do not need to be concerned here about the
    // final newline; it will be removed along with other possible whitespace
    // in the subsequent call to trimStr().

    fgets(pStr, kStringMax, inFileDesc);   // read one line
    len = trimStr(pStr);                   // strip whitespace

    if (len) {
        numNames++;   // count only non-empty names
    }
    return len;
}

// putName - write nameString, appending <newline>

void putName(char* pStr, FILE* outFileDesc){
    fputs(pStr, outFileDesc);   // write name
    fputc('\n', outFileDesc);   // add newline
}

// trimStr - Trims beginning and end of a string.
//           Creates a working copy of string, trims that,
//           and copies the trimmed string back to original.
//
//           Because a trimmed string will always be the same
//           or fewer characters than the original, the only
//           side effect of this function is the modification of
//           the original string in place.
//
// Parameter:
//   pString - pointer of string to be trimmed/modified.
// Returns:
//   The length of the string after trimming.

int trimStr(char* pStr){
    size_t first, last, lenIn, lenOut;
    first = last = lenIn = lenOut = 0;

    lenIn = strlen(pStr);
    char tmpStr[lenIn + 1];
    strcpy(tmpStr, pStr);      // work on a copy
    char* pTmp = tmpStr;

    // skip leading whitespace
    while (isspace(pTmp[first])) {
        first++;
    }
    pTmp += first;

    lenOut = strlen(pTmp);
    if (lenOut) {
        last = lenOut - 1;
        // skip trailing whitespace
        while (isspace(pTmp[last])) {
            last--;
        }
        pTmp[last + 1] = '\0';   // cut trailing part
    }

    lenOut = strlen(pTmp);
    if (lenIn != lenOut) {
        strcpy(pStr, pTmp);   // copy trimmed result back
    }
    return lenOut;
}

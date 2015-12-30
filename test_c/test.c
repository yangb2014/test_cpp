#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

    char *szTemp = (char *)malloc(10);
    free(szTemp);
    free(szTemp);

    return 0;
}

#include "getoptlong.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    static const arg_val_t args[] = {
        {"-u", "--username", E_ARGUMENT_TYPE_REQUIRED},
        {"-p", "--password", E_ARGUMENT_TYPE_REQUIRED},
    };
    arg_match_t uIndex = CheckForGetOptLong("-u", args, 2);
    arg_match_t pIndex = CheckForGetOptLong("-p", args, 2);

    printf("Found %s at index %d\n", "-u", uIndex.index);
    printf("Found %s at index %d\n", "-p", pIndex.index);

    return 0;
}
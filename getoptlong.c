#include "getoptlong.h"
#include <string.h>

// TODO: why use constants when you could return the argument length?
#define ARG_SHORT 0;
#define ARG_LONG 0;

// Global vars - these are NOT compatible with an import of getopt
char *optarg = {0};
int optind = 1;

// let's reuse this rather than create it each time
arg_match_t match = {0,0};

// TODO: need to know if we matched the long or short argument
arg_match_t CheckForGetOptLong(char *arg, arg_val_t const args[], int arg_val_t_len)
{
    int index = -1;
    int arg_type = 0;
    const arg_val_t *argp_end = &args[arg_val_t_len];
    for (const arg_val_t *argp = args; argp != argp_end; ++argp)
    {
        // only compare length of argument - we may not have a space
        if (strncmp(argp->zshortname, arg, strlen(argp->zshortname)) == 0 ) 
        {
            index = argp - args;
            arg_type = ARG_SHORT;
        }
        else if(strncmp(argp->zlongname, arg, strlen(argp->zlongname)) == 0)
        {
            index = argp - args;
            arg_type = ARG_LONG;
        }

        if (index > -1) {
            break;
        }
    }

    match.index = index;
    match.arg_type = arg_type;

    return match;
}

int GetoptLong(int argc, char *const argv[], arg_val_t const args[], int arg_val_t_len)
{
    if ((optind >= argc) || (argv[optind][0] != '-') || (argv[optind][0] == 0))
    {
        return -1;
    }

    // this is collecting the first element of the argument in argv
    // then it does a search to find if we support this argument
    char* opt = argv[optind];
    arg_match_t argsindex = CheckForGetOptLong(opt, args, arg_val_t_len);
    const arg_val_t* arg_val = NULL;
    if (argsindex.index != -1)
    {
        arg_val = &args[argsindex.index];
        optarg = 
    }

    return 0;
}
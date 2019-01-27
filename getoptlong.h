#ifndef __GET_OPT_LONG__
#define __GET_OPT_LONG__

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum
    {
        E_ARGUMENT_TYPE_REQUIRED = 0,
        E_ARGUMENT_TYPE_NONE = 1,
        E_ARGUMENT_TYPE_OPTIONAL = 2,
    } argument_type_t;

    typedef struct
    {
        char *zlongname;
        char *zshortname;
        argument_type_t e_atype;

    } arg_val_t;

    typedef struct
    {
        int index;
        int arg_type;
    } arg_match_t;

    extern char *optarg;
    extern int optind;

    int GetoptLong(int argc, char *const argv[], arg_val_t const args[], int arg_val_t_len);
    arg_match_t CheckForGetOptLong(char *arg, arg_val_t const args[], int arg_val_t_len);

#ifdef __cplusplus
}
#endif

#endif
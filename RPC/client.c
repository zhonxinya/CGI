 #include <rpc/rpc.h>
#include "data.h"

int main(int argc, char **argv)
{
    extern char *optarg;
    extern int optind;
    char *server = "localhost";   /* default */
    int err = 0, c;
    while ((c = getopt(argc, argv, "h:")) != -1)
    {
        switch (c)
        {
            case 'h':
                server = optarg;
                break;
            case '?':
                err = 1;
                break;
        }
    }

    /* exit if error or extra arguments */
    if (err || (optind < argc))
    {
        fprintf(stderr, "usage: %s [-h hostname]\n", argv[0]);
        exit(1);
    }

    CLIENT *cl; /* rpc handle */
    cl = clnt_create(server, DATE_PROG, DATE_VERS, "udp");

    long *lresult;
    if ((lresult = bin_date_2(NULL, cl)) == NULL)
    {
        clnt_perror(cl, server); /* failed! */
        exit(1);
    }
    printf("time on %s is %ld\n", server, *lresult);

    char **sresult;
    if ((sresult = str_date_2(lresult, cl)) == NULL)
    {
        /* failed ! */
        clnt_perror(cl, server);
        exit(1);
    }
    printf("date is %s", *sresult);

    clnt_destroy(cl);
    return 0;
}
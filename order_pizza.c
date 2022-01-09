# include <stdio.h>
# include <unistd.h>

int main (int argc, char *argv[])
{
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch = '\0';

    // read all options
    while ( (ch = getopt(argc, argv, "d:t")) != EOF)
    {
        switch(ch)
        {
            case 'd':
                // read the argument following -d
                delivery = optarg;
                break;

            case 't':
                thick = 1;
                break;

            default:
                fprintf(stderr, "Unknown Option: \'%s\'\n", optarg);

                return 1;
        }
    }

        // skip past the read options
        argc -= optind;
        argv += optind;

        if (thick)
            printf("Thick Crust.\n");

        if (delivery[0])
            printf("To be delivered: %s.\n", delivery);

        printf("Ingredients:\n");

        for (count = 0; count < argc; ++count)
            printf("%s\n", argv[count]);

    return 0;
}
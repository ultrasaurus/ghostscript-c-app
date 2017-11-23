#include "ierrors.h"
#include "iapi.h"

#include <stdio.h>

void *minst;

int main(int argc, char *argv[])
{
    int code, code1;
    char * gsargv[10];
    int gsargc;
    gsargv[0] = "pdf2png";	/* actual value doesn't matter */
    gsargv[1] = "-dNOPAUSE";
    gsargv[2] = "-dBATCH";
    gsargv[3] = "-dSAFER";
    gsargv[4] = "-sDEVICE=pngalpha";
    gsargv[5] = "-sOutputFile=out.png";
    gsargv[6] = "-r144";
    gsargv[7] = "sample.pdf";
    gsargc=8;

    code = gsapi_new_instance(&minst, NULL);
    if (code < 0) return 1;
    code = gsapi_set_arg_encoding(minst, GS_ARG_ENCODING_UTF8);
    if (code == 0)
        code = gsapi_init_with_args(minst, gsargc, gsargv);
    code1 = gsapi_exit(minst);

    if ((code == 0) || (code == gs_error_Quit))
	code = code1;

    gsapi_delete_instance(minst);

    if ((code == 0) || (code == gs_error_Quit))
	return 0;
    return 1;
}

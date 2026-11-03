#include <stdio.h>
#include <string.h>
#pragma force_active on

extern int fn_8036A24C(void *arg0, void *arg1, const void *src, int len);
extern char lbl_8059F698[3];

void fn_8036A384(void *arg0, void *arg1) {
    char buf[16];

    sprintf(buf, lbl_8059F698);
    fn_8036A24C(arg0, arg1, buf, strlen(buf));
}

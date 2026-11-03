#include <string.h>
#pragma force_active on

extern char lbl_8059F9A0;

void fn_80378B50(char **arg0, int *arg1) {
    char *temp_r5;

    temp_r5 = *arg0;
    if (temp_r5 == NULL) {
        *arg0 = &lbl_8059F9A0;
        *arg1 = 0;
        return;
    }
    if (*arg1 == -1) {
        *arg1 = strlen(temp_r5) + 1;
    }
}

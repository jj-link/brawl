#include <string.h>
#pragma force_active on

extern "C" {
extern char lbl_68_data_810[];

void fn_68_3E2C(char* dst, const char* src) {
    if (src != 0) {
        strcpy(dst + 0x9cd, lbl_68_data_810);
        strncpy(dst + 0x9cd, src, 0x7f);
    }
}
}

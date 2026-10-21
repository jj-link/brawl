#include <string.h>
#pragma force_active on

extern char lbl_8047C170[];

s32 fn_8020CA48(const char* str) {
    return strncmp(str, lbl_8047C170, 8) == 0;
}

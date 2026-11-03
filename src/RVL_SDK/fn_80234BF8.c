#include <string.h>
#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void fn_802324E0(void *arg);
void fn_80234BF8(const char *arg0) {
    short *p = (short *)fn_8022EE58(0x28);
    if (p != 0) {
        *p = 0x102;
        strncpy((char *)p + 8, arg0, 0x20);
        fn_802324E0(p);
    }
}
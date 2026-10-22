#include <types.h>
#pragma force_active on

extern void* fn_8022EFF8(int);
extern void fn_80242908(void*);

s32 fn_802461EC(char* arg0, s8 arg1) {
    char* p = (char*)fn_8022EFF8(2);
    if (p == NULL) {
        return 0;
    }
    *(unsigned short*)(p + 2) = 0xa;
    *(unsigned short*)(p + 4) = 0;
    p[8] = 0x12;
    p[9] = 0xc;
    p[0xa] = 7;
    p[0xb] = arg0[5];
    p[0xc] = arg0[4];
    p[0xd] = arg0[3];
    p[0xe] = arg0[2];
    p[0xf] = arg0[1];
    p[0x10] = arg0[0];
    p[0x11] = arg1;
    fn_80242908(p);
    return 1;
}

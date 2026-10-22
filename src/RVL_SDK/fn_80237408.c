#include <types.h>
#include <string.h>
#pragma force_active on

extern void *fn_8022EE58(unsigned short size);
extern void fn_802324E0(void *arg);

void fn_80237408(short arg0, int arg1) {
    void *ptr = fn_8022EE58(0x14);
    if (ptr) {
        memset(ptr, 0, 0x14);
        *(short *)ptr = 0x1708;
        *(short *)((char *)ptr + 6) = arg0;
        *(char *)((char *)ptr + 8) = 0xa;
        *(short *)((char *)ptr + 0xc) = 0;
        *(char *)((char *)ptr + 9) = 2;
        *(int *)((char *)ptr + 0x10) = arg1;
        *(char *)((char *)ptr + 0xa) = 0;
        fn_802324E0(ptr);
    }
}

#include <types.h>
#pragma force_active on

extern int fn_803E2458(void *self);

void fn_803DBFD0(void *arg0) {
    char *p = arg0;
    u16 i;
    for (i = 0; i < 3; i++) {
        char *r = p + i * 0x280;
        *(int *)(r + 0xe3c) = 0;
        fn_803E2458(r + 0xe44);
    }
    *(int *)(p + 0x15bc) &= 0xfffffffe;
    *(int *)(p + 0x15dc) &= 0xfffffffe;
    *(int *)(p + 0x15fc) &= 0xfffffffe;
    *(int *)(p + 0x1620) = 0;
}

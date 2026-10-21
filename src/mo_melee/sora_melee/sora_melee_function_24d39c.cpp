#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern "C" void fn_27_24D39C(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u8 *p;
    s32 off;
    s32 idx;
    s32 add;
    s32 i;

    *arg1 = 0;
    arg2[0] = 0;
    arg3[0] = 0;
    arg2[1] = 0;
    arg3[1] = 0;
    arg2[2] = 0;
    arg3[2] = 0;

    i = 0;
    off = 0;
    while (i < *(s32 *)(arg0 + 0x104)) {
        p = *(u8 **)(arg0 + 0xCC) + off;
        if (p[0x25] != 3) {
            idx = p[0x2A] * 4;
            *(s32 *)((u8 *)arg3 + idx) += 1;
            if ((s8)p[0x2E] != 0) {
                if (*(s32 *)((u8 *)arg2 + idx) == 0) {
                    (*arg1)++;
                }
                add = 1;
                if ((s8)p[0x2E] >= 1) {
                    add = (s8)p[0x2E];
                }
                *(s32 *)((u8 *)arg2 + idx) += add;
            }
        }
        off += 0x2AC;
        i++;
    }
}

#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void *fn_8022EFF8(int);
extern void fn_80242908(void *);

int fn_80245974(void *arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    u8 *p = (u8 *)arg0;

    if (p == 0) {
        p = (u8 *)fn_8022EFF8(2);
        if (p == 0) {
            return 0;
        }
    }

    *(u16 *)(p + 2) = 0x000D;
    *(u16 *)(p + 4) = 0;
    p[8] = 3;
    p[9] = 8;
    p[10] = 0xA;
    p[11] = (u8)arg1;
    p[12] = (u8)(arg1 >> 8);
    p[13] = (u8)arg2;
    p[14] = (u8)(arg2 >> 8);
    p[15] = (u8)arg3;
    p[16] = (u8)(arg3 >> 8);
    p[17] = (u8)arg4;
    p[18] = (u8)(arg4 >> 8);
    p[19] = (u8)arg5;
    p[20] = (u8)((arg5 >> 8) & 0xFFFF);

    fn_80242908(p);
    return 1;
}
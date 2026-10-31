#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;

extern void *fn_8022EFF8(int);
extern void fn_80242908(void *);

int fn_80245AC4(void *arg0, int arg1, int arg2, unsigned int arg3)
{
    u8 *p = (u8 *)arg0;

    if (p == 0) {
        p = (u8 *)fn_8022EFF8(2);
        if (p == 0) {
            return 0;
        }
    }

    *(u16 *)(p + 2) = 9;
    *(u16 *)(p + 4) = 0;
    p[8] = 5;
    p[9] = 8;
    p[10] = 6;
    p[11] = (u8)arg1;
    p[12] = (u8)(arg1 >> 8);
    p[13] = (u8)arg2;
    p[14] = (u8)(arg2 >> 8);
    p[15] = (u8)arg3;
    p[16] = (u8)(arg3 >> 8);

    fn_80242908(p);
    return 1;
}

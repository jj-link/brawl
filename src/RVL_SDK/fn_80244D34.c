#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *fn_8022EFF8(int);
extern void fn_80242908(void *);
int fn_80244D34(u8 *a, u8 *b) {
    u8 *p = fn_8022EFF8(2);
    int i;
    if (!p) return 0;
    *(u16 *)(p + 2) = 25;
    *(u16 *)(p + 4) = 0;
    p[8] = 11;
    p[9] = 4;
    p[10] = 22;
    for (i = 0; i < 6; i++) p[11+i] = a[5-i];
    for (i = 0; i < 16; i++) p[17+i] = b[15-i];
    fn_80242908(p);
    return 1;
}
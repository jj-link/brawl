#pragma force_active on
typedef unsigned char u8;
typedef short s16;

typedef struct {
    u8 pad0[2];
    s16 f2;
    s16 f4;
    u8 pad1[2];
    u8 f8;
    u8 f9;
    u8 fa;
    u8 fb;
} S;

extern void fn_80242908(void *p);

void fn_80246EB4(void *arg0, u8 arg1) {
    S *p = (S *)arg0;
    p->f2 = 4;
    p->f4 = 0;
    p->f8 = 0x47;
    p->f9 = 0xC;
    p->fa = 1;
    p->fb = arg1;
    fn_80242908(arg0);
}

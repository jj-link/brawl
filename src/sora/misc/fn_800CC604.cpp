#include <types.h>
#pragma force_active on
extern "C" {
extern char lbl_80457DC8[];
void netReport__FPCce(const char*, ...);
void* memset(void*, int, unsigned long);
void fn_800CCF30(void*, int, int, int, int);
}
struct State {
    u8 a, b, c, d, e, f, g, h, i, j, k, l, m;
    u16 n, o, p, q, r, s, t, u, v;
    u8 w, x;
    u16 y;
};
extern "C" void fn_800CC604(u8* self, int arg1)
{
    netReport__FPCce(lbl_80457DC8);
    u8* p = self + 0x1024;
    memset(p, 0, 0x24);
    p[1] = 0;
    p[2] = 2;
    p[3] = 2;
    p[4] = 0;
    p[5] = 10;
    p[6] = 1;
    p[7] = 0;
    p[9] = 0;
    p[8] = 0;
    p[12] = 0;
    p[10] = 0;
    *(State*)(self + 0x1000) = *(State*)(self + 0x1024);
    fn_800CCF30(self, arg1, 0, 2, -1);
}
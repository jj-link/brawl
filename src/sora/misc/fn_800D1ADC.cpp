#include <types.h>
#pragma force_active on
extern "C" u8 fn_800C851C();
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);
extern "C" void fn_80146878(void*, int);
extern "C" void fn_801473C4();
extern "C" void netReport__FPCce(const char*, ...);
extern int lbl_805A03A8;
extern char g_Network[];
extern char lbl_8045879C[];
struct Flags { u8 rest : 7; u8 flag : 1; };

extern "C" void fn_800D1ADC(u8* self, int arg1) {
    if (arg1 == 0) {
        fn_80146878(g_Network, 0);
        *(int*)(self + 0x1048) = 0;
        *(int*)(self + 0x104c) = 0;
        fn_801473C4();
    } else {
        u8 i = fn_800C851C();
        if (i == 0xff) i = 4;
        u8* p = self + i * 0x218;
        p[0xc6] |= 0x20;
        u8 j = fn_800C851C();
        if (j == 0xff) j = 4;
        u8* q = self + j * 0x218;
        ((Flags*)(q + 0xc6))->flag = 0;
        fn_800D0AE0(self, q);
        fn_80145B98(lbl_805A03A8, 0xfe);
        u8 k = fn_800C851C();
        if (k == 0xff) k = 4;
        netReport__FPCce(lbl_8045879C, k);
    }
}
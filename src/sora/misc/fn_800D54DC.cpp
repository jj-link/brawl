#pragma force_active on
typedef unsigned char u8;
struct WordFlags { unsigned int top : 8; unsigned int rest : 24; };
struct Flags { u8 rest : 7; u8 flag : 1; };
extern char lbl_80457158[];
extern int lbl_805A03A8;
extern "C" u8 fn_800C851C();
extern "C" u8 fn_800C8548();
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);
extern "C" int fn_800D54DC(char* self) {
    char* base = lbl_80457158;
    u8 i = fn_800C851C();
    if (i == 0xff) i = 4;
    if (i == 4) { netReport__FPCce(base + 0x1b78); return 0; }
    u8 j = fn_800C8548();
    char* q;
    if (j == 0xff) q = 0;
    else q = (char*)((int)self + 0x70 + j * 0x218);
    if ((bool)q == false) { netReport__FPCce(base + 0x1b90); return 0; }
    ((WordFlags*)(self + 0xfcc))->top = 1;
    netReport__FPCce(base + 0x1bb0);
    u8 k = fn_800C851C();
    if (k == 0xff) k = 4;
    char* e = self + k * 0x218;
    ((Flags*)(e + 0xc6))->flag = 1;
    fn_800D0AE0(self, e);
    fn_80145B98(lbl_805A03A8, 0xfe);
    return 1;
}
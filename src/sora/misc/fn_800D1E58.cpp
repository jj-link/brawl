#pragma force_active on
typedef unsigned char u8;
struct Flags {
    u8 rest : 7;
    u8 flag : 1;
};
extern char lbl_804587CC[];
extern int lbl_805A03A8;
extern "C" void netReport__FPCce(const char*, ...);
extern "C" u8 fn_800C851C();
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);

extern "C" void fn_800D1E58(char* self, u8 v) {
    u8 i = fn_800C851C();
    if (i == 0xff) i = 4;
    char* e = self + i * 0x218;
    e[0xca] = v;
    netReport__FPCce(lbl_804587CC, v, e);
    u8 j = fn_800C851C();
    if (j == 0xff) j = 4;
    char* f = self + j * 0x218;
    ((Flags*)(f + 0xc6))->flag = 0;
    fn_800D0AE0(self, f);
    fn_80145B98(lbl_805A03A8, 0xfe);
}

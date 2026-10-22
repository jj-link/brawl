#pragma force_active on
typedef unsigned char u8;
struct Flags {
    u8 rest : 7;
    u8 flag : 1;
};
extern int lbl_805A03A8;
extern "C" u8 fn_800C851C();
extern "C" void fn_8010F960(u8, void*, void*, int);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);

extern "C" void fn_800CA73C(char* self, int a) {
    u8 i = fn_800C851C();
    if (i == 0xff) i = 4;
    char* p = self + i * 0x218;
    *(u8*)(p + 0xc2) = a;
    fn_8010F960(a, p + 0xc3, p + 0x7c, 0);
    u8 j = fn_800C851C();
    if (j == 0xff) j = 4;
    char* q = self + j * 0x218;
    ((Flags*)(q + 0xc6))->flag = 0;
    fn_800D0AE0(self, q);
    fn_80145B98(lbl_805A03A8, 0xfe);
}

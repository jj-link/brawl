#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Flags {
    u8 rest : 7;
    u8 flag : 1;
};
struct Field2 {
    u8 hi : 4;
    u8 f : 2;
    u8 lo : 2;
};
extern int lbl_805A03A8;
extern "C" u8 fn_800C851C();
extern "C" u8 fn_800C8548();
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);

extern "C" void fn_800D846C(char* self, int a) {
    u8 i = fn_800C851C();
    if (i == 0xff) i = 4;
    char* p = self + i * 0x218;
    ((Field2*)(p + 0xd4))->f = a;
    u8 j = fn_800C8548();
    char* q;
    if (j == 0xff) {
        q = 0;
    } else {
        q = self + j * 0x218 + 0x70;
    }
    if (q != 0) {
        ((Field2*)(q + 0x7d))->f = a;
    }
    u8 k = fn_800C851C();
    if (k == 0xff) k = 4;
    char* e = self + k * 0x218;
    ((Flags*)(e + 0xc6))->flag = 1;
    fn_800D0AE0(self, e);
    fn_80145B98(lbl_805A03A8, 0xfe);
}

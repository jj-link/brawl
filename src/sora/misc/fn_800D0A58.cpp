#include <types.h>
#pragma force_active on

extern "C" u8 fn_800C851C(void);
extern "C" void fn_800D0AE0(void* self, void* sub);
extern "C" void fn_80145B98(int a, int b);
extern int lbl_805A03A8;

struct fn800D0A58Sub {
    u8 pad[0xC6];
    u8 hi : 7;
    u8 lo : 1;
};

extern "C" void fn_800D0A58(char* self, u32 flag, int arg) {
    u8 idx = fn_800C851C();
    if (idx == 0xFF) {
        idx = 4;
    }
    char* sub = self + idx * 0x218;
    ((fn800D0A58Sub*)sub)->lo = flag;
    fn_800D0AE0(self, sub);
    fn_80145B98(lbl_805A03A8, arg);
}

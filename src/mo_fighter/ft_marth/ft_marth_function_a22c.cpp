#include <types.h>
#pragma force_active on

extern "C" {
void fn_106_A1DC(void* p, void* q);
void fn_106_A3AC(s16* dst, const s16* src);
void fn_106_A2BC(void* p, s16* src, void* q);
}

struct MarthFlagByte {
    u8 hi : 1;
    u8 rest : 7;
};

extern "C" void fn_106_A22C(u8* self, s16* src, void* arg) {
    s16 local[4];
    u8* sub = self + 0xc;
    if (*src & 0x8) {
        MarthFlagByte* fb = (MarthFlagByte*)(sub + 5);
        bool f = fb->hi;
        if (f == true && sub[6] == 0) {
            fn_106_A1DC(sub, arg);
        }
    }
    fn_106_A3AC(local, src);
    fn_106_A2BC(self + 4, local, arg);
}

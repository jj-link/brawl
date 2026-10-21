#include <types.h>
#pragma force_active on

extern "C" {
void fn_106_9D54(u8* obj, s32 arg);
void fn_106_A3AC(s16* dst, const s16* src);
void fn_106_9E34(u8* obj, s16* src, s32 arg);

struct SubBits {
    u8 flag : 1;
    u8 rest : 7;
};

struct SubObj {
    u8 pad[5];
    SubBits b5;
    u8 b6;
};

void fn_106_9DA4(u8* self, s16* p, s32 arg) {
    SubObj* sub = (SubObj*)(self + 0xc);
    if (p[0] & 1) {
        bool f = sub->b5.flag;
        if (f == 1 && sub->b6 == 0) {
            fn_106_9D54((u8*)sub, arg);
        }
    }
    s16 buf[4];
    fn_106_A3AC(buf, p);
    fn_106_9E34(self + 4, buf, arg);
}
}

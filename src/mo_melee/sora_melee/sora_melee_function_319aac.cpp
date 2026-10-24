#include <types.h>
#pragma force_active on

struct Input {
    s16 bits;

    Input(const Input& other) : bits(other.bits) {}
};

struct Sub {
    u8 pad[5];
    u8 f : 1;
    u8 g : 7;
    u8 h;
};

extern "C" void fn_27_31AA10(Sub*, s32);
extern "C" void fn_27_319B44(void*, Input, s32);

extern "C" void fn_27_319AAC(u8* self, const Input& p, s32 v) {
    Sub* sub = (Sub*)(self + 0xC);

    if ((p.bits & 1) && (bool)sub->f == true && sub->h == 0) {
        fn_27_31AA10(sub, v);
    }

    Input local(p);
    fn_27_319B44(self + 4, local, v);
}

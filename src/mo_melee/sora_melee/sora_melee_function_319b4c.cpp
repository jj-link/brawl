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

extern "C" void fn_27_31ADEC(void*, s32);
extern "C" void fn_27_319BE4(void*, Input, s32);

extern "C" void fn_27_319B4C(u8* self, Input input, s32 v) {
    Input local(input);
    Sub* sub = (Sub*)(self + 0xC);

    if ((local.bits & 1) && (bool)sub->f == true && sub->h == 0) {
        fn_27_31ADEC(sub, v);
    }

    fn_27_319BE4(self + 4, input, v);
}

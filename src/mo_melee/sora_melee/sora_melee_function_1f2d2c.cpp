#include <types.h>
#pragma force_active on

struct Inner {
    char pad[0x110];
    s8 mValue;
};

struct Outer {
    char pad[0x4c];
    Inner* mArr[7];
};

extern "C" {
s32 fn_27_1F2D2C(Outer* self, s32 idx) {
    if (idx >= 0 && idx < 7 && self->mArr != nullptr) {
        Inner* p = self->mArr[idx];
        if (p != nullptr) {
            return p->mValue;
        }
    }
    return -1;
}
}

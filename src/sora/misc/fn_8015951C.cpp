#include <types.h>
#pragma force_active on

struct UnkObj {
    u8 pad[0x18];
    void* unk18;
    u8 pad2[4];
    s32 unk20;
};

extern "C" void __dla__FPv(void* p);

extern "C" void fn_8015951C(UnkObj* self) {
    if (self->unk18 != nullptr) {
        __dla__FPv(self->unk18);
        self->unk18 = nullptr;
    }
    self->unk20 = 0;
}

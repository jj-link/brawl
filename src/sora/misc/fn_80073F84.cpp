#include <types.h>
#pragma force_active on

struct SndObj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};

struct SndSystem {
    unsigned char pad[0x6e0];
    SndObj* unk6e0;
    s32 unk6e4;
    unsigned char pad6e8[4];
    unsigned char unk6ec;
    unsigned char pad6ed[2];
    unsigned char unk6ef;
};

extern "C" void fn_80073F84(SndSystem* self) {
    if (self->unk6ef != 0 && self->unk6ec != 0) {
        if (self->unk6e0) {
            self->unk6e0->slot4();
        }
        self->unk6e4 = -1;
    }
}

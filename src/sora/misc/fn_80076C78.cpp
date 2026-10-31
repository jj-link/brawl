#include <types.h>
#pragma force_active on

extern "C" const float lbl_805A1AC8;

struct SndObj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int);
};

struct SndSystem {
    unsigned char padding[0x6e0];
    SndObj* unk6e0;
    s32 unk6e4;
    unsigned char pad6e8[4];
    unsigned char unk6ec;
    unsigned char pad6ed[2];
    unsigned char unk6ef;
    unsigned char pad6f0[0x10];
    float unk700;
    unsigned char pad704[4];
    float unk708;
    unsigned char pad70c[4];
    unsigned char pad710[0x10];
    unsigned char unk720;
    unsigned char pad721[3];
    s32 unk724;
};

extern "C" void fn_80076C78(SndSystem* self) {
    self->unk720 = 0;
    float f = lbl_805A1AC8;
    self->unk708 = f;
    self->unk700 = f;
    if (self->unk724 == 1 && self->unk6ef != 0 && self->unk6ec != 0) {
        if (self->unk6e0) {
            self->unk6e0->slot4(0);
        }
        self->unk6e4 = -1;
    }
}

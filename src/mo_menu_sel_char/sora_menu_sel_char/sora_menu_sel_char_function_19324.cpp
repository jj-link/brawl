#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_10_rodata_6A8;
}

struct MuObject {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float getFrameMatCol();
};

struct Inner {
    char pad[8];
    MuObject* object;
};

struct Middle {
    char pad[0x14];
    Inner* inner;
};

struct Self {
    char pad[0x144];
    Middle* member;
};

extern "C" bool fn_10_19324(Self* self) {
    float value = self->member->inner->object->getFrameMatCol();
    return lbl_10_rodata_6A8 != value;
}

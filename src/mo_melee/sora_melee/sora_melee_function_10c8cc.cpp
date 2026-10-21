#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_F0C;

struct ValuesBase {
    u8 pad[0xc];
};

struct Values : ValuesBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual float value();
};

struct Item {
    u8 pad0[4];
    s32 id;
    u8 pad8[0x20];
    Values* values;
};

struct Inner {
    virtual ~Inner();
    virtual Item** getItem(s32 index);
    virtual void f4();
    virtual s32 getCount();
};

struct Outer {
    u8 pad[8];
    Inner inner;
};

struct Holder {
    u8 pad[0x154];
    Outer* outer;
};

extern "C" float fn_27_10C8CC(Holder* self, s32 id) {
    float result = lbl_27_rodata_F0C;
    s32 count = self->outer->inner.getCount();
    for (s32 i = 0; i < count; ++i) {
        if (id != (*self->outer->inner.getItem(i))->id) {
            float value = (*self->outer->inner.getItem(i))->values->value();
            if (result < value) {
                result = value;
            }
        }
    }
    return result;
}

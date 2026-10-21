#include <types.h>
#pragma force_active on

class Item {
public:
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0x50];
    s32 unk58;
};

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual Item** get(s32 index);
    virtual s32 count();
};

class Outer {
public:
    u8 m_pad[8];
    Inner inner;
};

extern "C" {
s32 fn_27_1193BC(Outer* self, s32 key) {
    s32 n = self->inner.count();
    for (s32 i = 0; i < n; i++) {
        if (key == (*self->inner.get(i))->unk58) {
            return (*self->inner.get(i))->unk4;
        }
    }
    return -1;
}
}

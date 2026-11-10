#include <types.h>
#pragma force_active on

class Class_804864A0 {
public:
    virtual void fn_802814B8();  // offset 0x8
    virtual void fn_80080A64();  // offset 0xc
    virtual void fn_80281744();  // offset 0x10
    virtual void fn_80281640();  // offset 0x14
    virtual void fn_802816FC();  // offset 0x18
    virtual void fn_802817A4();  // offset 0x1c
    virtual void fn_802817EC();  // offset 0x20
    virtual s32 fn_802818D4();   // offset 0x24
};

struct Outer {
    char pad[0x8];
    Class_804864A0* unk8;
    char pad2[0x4];
    s32 unk10;
};

extern "C" s32 fn_802818D4(Outer* self) {
    s32 r;
    if (self->unk8 != 0) {
        r = self->unk8->fn_802818D4();
    } else {
        r = 0;
    }
    if (r >= 0) {
        return r + self->unk10;
    }
    return -1;
}

#include <types.h>

#pragma force_active on

class Inner {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual u32 slot1C();
};

class Class_804864A0 {
public:
    virtual void fn_802814B8();
    virtual void fn_80080A64();
    virtual void fn_80281744();
    virtual void fn_80281640();
    virtual void fn_802816FC();
    virtual void fn_802817A4();
    u32 unk4;
    Inner* unk8;
};

extern "C" u32 fn_802817A4(Class_804864A0* self) {
    u32 result;
    if (self->unk8 != 0) {
        result = self->unk8->slot1C() >> 24;
    } else {
        result = 1;
    }
    return result << 24;
}

#include <types.h>
#pragma force_active on

namespace {
struct SomeObject {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual u32 slot58();
};

struct Holder {
    u8 padding[0x1C];
    SomeObject* ptr;
};
} // namespace

extern "C" u32 fn_8032C19C(Holder* self) {
    u32 result = 1;
    if (self->ptr != 0) {
        u32 val = self->ptr->slot58();
        if ((s8)(val >> 24) == 0) {
            result = 0;
        }
    }
    return result << 24;
}

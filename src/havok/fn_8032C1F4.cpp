#include <types.h>
#pragma force_active on

namespace {
class FnTarget {
public:
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
    virtual void slot58();
    virtual u32 slot5C();
};

struct FnOwner {
    u8 pad[0x1C];
    FnTarget* target;
};
}

extern "C" {
int fn_8032C1F4(FnOwner* self) {
    int result = 1;
    FnTarget* target = self->target;
    if (target != 0) {
        s8 flag = (s8)(target->slot5C() >> 24);
        if (flag == 0) {
            result = 0;
        }
    }
    return result << 24;
}
}

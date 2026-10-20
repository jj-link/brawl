#include <types.h>
#pragma force_active on

class fnSubObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual u32 size();
};

struct fnOwner {
    u8 pad[0x10];
    fnSubObj sub;
};

struct fnElem {
    u8 pad[0x18];
    u8 flag : 1;
    u8 rest : 7;
};

extern "C" bool fn_27_D8AD0(fnOwner* self, s32 index) {
    if (index < 0 || index >= (s32)self->sub.size()) {
        return false;
    }
    fnElem* e = (fnElem*)((u8*)self + index * 0x14);
    return e->flag;
}

#include <types.h>
#pragma force_active on

class HeapAllocator {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void* ptr, u16 type, s32 align);
};

extern HeapAllocator* lbl_805A0EB8;

struct Obj {
    void* vtable;
    u16 type;
};

extern "C" void* fn_8027C724(void* arg0, s32 arg1) {
    Obj* self = (Obj*)arg0;
    if (self != 0 && arg1 > 0) {
        lbl_805A0EB8->slot5(self, self->type, 0x16);
    }
    return self;
}

#include <types.h>
#pragma force_active on

class PeachBase {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual u32 slot9(u32 arg);
};

extern "C" {
PeachBase* fn_103_9190(void* self);
void* fn_27_135A70(void* object);

u32 fn_103_9420(void* self) {
    PeachBase* obj = fn_103_9190(self);
    u32 arg = *reinterpret_cast<u32*>(static_cast<u8*>(self) + 0x60);
    u32 result = obj->slot9(arg);
    if (result == 1) {
        return 1;
    }
    return reinterpret_cast<u32>(fn_27_135A70(self));
}
}

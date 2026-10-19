#include <types.h>
#pragma force_active on

class MetaKnightSlot {
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
    virtual s32 slot9(s32 index);
};

extern "C" s32 fn_111_D5E0(void* unused, u8* owner) {
    for (s32 index = 6; index < 12; ++index) {
        MetaKnightSlot* target = *(MetaKnightSlot**)(*(u8**)(owner + 0xD8) + 0x54);
        if (target->slot9(index) == 0) {
            return index;
        }
    }
    return -1;
}

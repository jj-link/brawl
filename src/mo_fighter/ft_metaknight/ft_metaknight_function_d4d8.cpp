#include <types.h>
#pragma force_active on

class MetaKnightTarget {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4(s32 index, u32 value);
};

extern "C" s32 fn_111_D5E0(void* unused, u8* owner);

extern "C" void fn_111_D4D8(void* unused, u8* data, u8* owner) {
    if (data != 0) {
        s32 index = fn_111_D5E0(unused, owner);
        if (index >= 0) {
            MetaKnightTarget* target =
                *(MetaKnightTarget**)(*(u8**)(owner + 0xD8) + 0x54);
            if (target->slot4(index, *(u32*)(data + 0xC)) != 0) {
                return;
            }
        }
    }
}

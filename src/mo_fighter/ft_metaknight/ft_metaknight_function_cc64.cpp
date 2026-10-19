#include <types.h>
#pragma force_active on

class MetaKnightComponent {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4(s32 id);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(s32 id);
};

extern "C" void fn_111_CC64(void* unused, u8* owner) {
    MetaKnightComponent* component =
        *reinterpret_cast<MetaKnightComponent**>(*reinterpret_cast<u8**>(owner + 0xd8) + 0x64);
    if (component->slot4(0x20000002) > 0) {
        component =
            *reinterpret_cast<MetaKnightComponent**>(*reinterpret_cast<u8**>(owner + 0xd8) + 0x64);
        component->slot8(0x20000002);
    }
}

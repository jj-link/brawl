#include <types.h>
#pragma force_active on

class Slot { public: char pad[0x4d4]; };
class SlotManager { public: Slot* slots; s32 count; };
extern SlotManager* g_ftSlotManager;
extern s32 lbl_27_bss_31F8;
extern "C" u32 fn_27_120748(Slot*, s32);
extern "C" u32 fn_27_115B34(void*);
extern "C" s32 fn_27_145028(s32);

class ItemList {
public:
    virtual void vf0();
    virtual void** getAt(s32);
    virtual void vf4();
    virtual s32 getCount();
};
class Holder { public: u32 pad[2]; ItemList list; };
class Owner { public: char pad[0x154]; Holder* holder; };

extern "C" s32 fn_27_10A35C(Owner* self) {
    s32 count = g_ftSlotManager->count;
    for (s32 i = 0; i < count; i++) {
        if (fn_27_120748(&g_ftSlotManager->slots[i], 0x7000) == 1U)
            return 1;
    }
    s32 itemCount = self->holder->list.getCount();
    for (s32 i = 0; i < itemCount; i++) {
        if (fn_27_115B34(*self->holder->list.getAt(i)) == 1U)
            return 1;
    }
    return fn_27_145028(lbl_27_bss_31F8) == 0;
}

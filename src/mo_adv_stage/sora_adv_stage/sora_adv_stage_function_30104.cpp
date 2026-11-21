#include <gr/gr_yakumono.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_40_rodata_570;
extern "C" float lbl_40_rodata_5BC;

struct StageTimerData {
    char pad[0x15c];
    int state;
    char pad2[8];
    float timer;
};

struct StageSlot {
    char pad[0x174];
    StageTimerData* obj;
};

extern "C" void fn_40_30104(grYakumono* self, const u32* index, float delta) {
    StageTimerData* obj;
    StageSlot* slot;
    u32 element;
    float timer;

    element = *index;
    slot = (StageSlot*)((char*)self + element * 4);
    obj = slot->obj;

    timer = obj->timer - delta;
    obj->timer = timer;
    if (timer < lbl_40_rodata_570) {
        slot->obj->state = 3;
    }
    if (obj->timer < lbl_40_rodata_5BC) {
        self->grYakumono::disableAttack(*index);
        self->grYakumono::disableHit(*index, 0);
        self->grYakumono::setTeamYakumono(0x12, -1);
    }
}
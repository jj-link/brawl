#include <gr/gr_tengan_event.h>
#include <gr/gr_madein.h>
#include <st/st_melee.h>
#include <mt/mt_prng.h>
#pragma force_active on

extern "C" const float lbl_60_rodata_0[];

struct StageT {
    char pad0[0x6d0];
    grTenganEvent event1;
    grTenganEvent event2;
    char pad828[0x63c];
    float remaining;
    bool used[3];
    char padE6B[0x35];
    int sound;
};

extern "C" int fn_60_2C64(StageT* self) {
    const float* constants = lbl_60_rodata_0;
    switch (self->event1.getPhase()) {
    case 0: {
        self->sound = ((stMelee*)self)->playSeBasic((SndID)0x1c41, constants[0]);
        unsigned int index = randi(2);
        if (index >= 1) index = 1;
        ((stMelee*)self)->playSeBasic((SndID)(index + 0x1c42), constants[0]);
        self->event1.setPhase(1);
        break;
    }
    case 1:
        if (self->event1.isReadyEnd() == true) {
            float r = randf();
            unsigned int index;
            if (r < constants[34]) index = 0;
            else if (r < constants[35]) index = 1;
            else index = 2;
            if (self->used[index] != true && self->event2.start() == true) {
                self->used[index] = true;
                self->remaining = self->event2.m_framesLeft;
                if (index == 1) {
                    ((grMadein*)((stMelee*)self)->getGround(0x1b))->startEntity();
                    ((stMelee*)self)->getGround(0x1b)->setEnableCollisionStatus(true);
                }
                return 1;
            }
        }
        break;
    }
    return 0;
}
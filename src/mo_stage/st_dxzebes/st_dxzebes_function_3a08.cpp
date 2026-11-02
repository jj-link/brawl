#include <st/st_melee.h>
#include <st/stage.h>
#include <gr/gr_madein.h>
#pragma force_active on

extern "C" {
extern const float lbl_84_rodata_0[];
}

extern "C" void fn_84_3A08(stMelee* self) {
    const float* rodata = lbl_84_rodata_0;
    s16 state = *(s16*)((char*)self + 0x4CC);
    switch (state) {
    case 0:
        if (*(float*)((char*)self + 0x4B4) > rodata[0x1E4 / 4]) {
            self->playSeBasic((SndID)0x1DAB, rodata[0x28 / 4]);
            *(s16*)((char*)self + 0x4CC) = 1;
            ((grMadein*)((Stage*)self)->getGround(7))->setMotion(2);
            ((grMadein*)((Stage*)self)->getGround(7))->startEntity();
        } else if (*(float*)((char*)self + 0x4B4) > rodata[0x200 / 4]) {
            self->playSeBasic((SndID)0x1DAB, rodata[0x28 / 4]);
            ((grMadein*)((Stage*)self)->getGround(7))->setMotion(1);
            ((grMadein*)((Stage*)self)->getGround(7))->startEntity();
            *(s16*)((char*)self + 0x4CC) = 1;
        }
        break;
    case 1:
        if (((grMadein*)((Stage*)self)->getGround(7))->isEndEntity()) {
            ((grMadein*)((Stage*)self)->getGround(7))->setMotion(0);
            ((grMadein*)((Stage*)self)->getGround(7))->startEntityAutoLoop();
            *(s16*)((char*)self + 0x4CC) = 0;
        }
        break;
    }
}

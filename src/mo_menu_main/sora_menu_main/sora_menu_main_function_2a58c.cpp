#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

struct Owner {
    char pad0[0x67C];
    MuObject* object;
    char pad680[0x14];
    s32 unk694;
    s32 unk698;
    s32 unk69C;
    s32 unk6A0;
    s32 unk6A4;
};

extern "C" void fn_2_2A58C(void* p, s32 arg1) {
    Owner* arg0 = (Owner*)p;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6 = 0;

    if (arg1 != 0) {
        if (arg0->unk6A0 == 0) {
            s32 temp_r5 = arg0->unk694;
            if (temp_r5 < arg0->unk6A4 - 1) {
                var_r6 |= 2;
            }
            if (temp_r5 > 0) {
                var_r6 |= 1;
            }
        } else {
            s32 temp_r4 = arg0->unk698;
            if (temp_r4 + 7 < 0x18) {
                var_r6 |= 2;
            }
            if (temp_r4 > 0) {
                var_r6 |= 1;
            }
        }
        var_r5 = ((Owner*)p)->unk6A0;
    } else {
        var_r5 = 2;
    }

    if (var_r5 != 2) {
        var_r4 = 0;
        if (var_r6 & 1) {
            var_r4 |= 2;
        }
        if (var_r6 & 2) {
            var_r4 |= 1;
        }
        if (var_r5 == 1) {
            var_r4 += 4;
        }
    } else {
        var_r4 = 8;
    }

    arg0->object->setFrameVisible((f32)var_r4);
}
#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_80073F84(sndSystem*, u32);

struct BGMState {
    char pad[0x178];
    s32 id;
    s32 timer;
    s32 field180;
    char pad184[8];
    u8 field18C;
};

extern "C" void fn_80078EB8(BGMState* self, u32 selection, u32 fade) {
    s32 id;
    switch (self->id) {
    case 0x2751:
        if (selection - 2 <= 1U) {
            fn_80073F84(g_sndSystem, fade);
            self->id = 0x2756;
            self->field180 = 0;
            self->field18C = 1;
            self->timer = 120;
        }
        break;
    case 0x2756:
        if (selection <= 1U) {
            fn_80073F84(g_sndSystem, fade);
            self->id = 0x2751;
            self->field180 = 0;
            self->field18C = 1;
            self->timer = 120;
        }
        break;
    case 0x27a1:
        fn_80073F84(g_sndSystem, fade);
        switch (selection) {
        case 0: id = 0x27a9; break;
        case 1: id = 0x27aa; break;
        case 2: id = 0x27ab; break;
        case 3: id = 0x27ac; break;
        case 4: id = 0x27ad; break;
        case 5: id = 0x27ae; break;
        case 6: id = 0x27af; break;
        case 7: id = 0x27b0; break;
        case 8: id = 0x27b1; break;
        case 9: id = 0x27b2; break;
        default: id = 0x27a1; break;
        }
        self->id = id;
        g_sndSystem->playBGM(id, fade, true);
        break;
    case 0x27a9:
    case 0x27aa:
    case 0x27ab:
    case 0x27ac:
    case 0x27ad:
    case 0x27ae:
    case 0x27af:
    case 0x27b0:
    case 0x27b1:
    case 0x27b2:
        fn_80073F84(g_sndSystem, fade);
        if (selection == 10) {
            self->id = 0x27a1;
            g_sndSystem->playBGM(0x27a1, fade, true);
        } else {
            switch (selection) {
        case 0: id = 0x27a9; break;
        case 1: id = 0x27aa; break;
        case 2: id = 0x27ab; break;
        case 3: id = 0x27ac; break;
        case 4: id = 0x27ad; break;
        case 5: id = 0x27ae; break;
        case 6: id = 0x27af; break;
        case 7: id = 0x27b0; break;
        case 8: id = 0x27b1; break;
        case 9: id = 0x27b2; break;
            default: id = 0x27a1; break;
            }
            self->id = id;
            g_sndSystem->playBGM(id, fade, true);
        }
        break;
    }
}

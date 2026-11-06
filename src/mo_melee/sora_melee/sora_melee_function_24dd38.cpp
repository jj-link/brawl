#include <types.h>
#pragma force_active on

extern "C" void fn_27_24DD38(void* self) {
    u8* p = (u8*)self;
    u8 selected = 0;
    for (int i = 0; i < 4; i++) {
        if (p[0x25 + i * 0x2AC] != 3 && p[0x33 + i * 0x2AC] == 0) {
            selected = i;
        }
    }
    p[0x1D] = selected;
    selected = 0;
    for (int i = 0; i < 3; i++) {
        if (p[0x1306 + i * 0x30] != 0 && p[0x1305 + i * 0x30] == 0) {
            selected = i;
        }
    }
    p[0x1E] = selected;
    if (p[2] == 1) {
        u8* current = p;
        u8 team;
        int candidate;
        for (int i = 0; i < 4; current += 0x2AC, i++) {
            if (current[0x25] == 3) continue;
            team = p[0x1E];
            if (team == current[0x2A]) {
                candidate = i;
                for (int j = 0; j < 4; j++) {
                    if (p[0x25 + j * 0x2AC] != 3 &&
                        team == p[0x2A + j * 0x2AC] &&
                        i != j &&
                        current[0x33] > p[0x33 + j * 0x2AC]) {
                        candidate = -1;
                        break;
                    }
                }
                if (candidate >= 0) {
                    p[0x1F] = candidate;
                    return;
                }
            }
        }
    } else {
        p[0x1F] = p[0x1D];
    }
}

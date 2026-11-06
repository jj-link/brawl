#pragma force_active on

#include <gm/gm_global.h>

extern "C" float randf__Fv();
extern "C" const float lbl_46_rodata_14;

struct DolPic {
    unsigned char pad0[0x9C];
    unsigned char* unk9C;
    unsigned char padA0[0x138];
    unsigned char unk1D8;
    unsigned char pad1D9[7];
    unsigned char unk1E0;
    unsigned char unk1E1;
    unsigned char unk1E2;
    unsigned char unk1E3;
};

extern "C" void fn_46_1EE8(DolPic* self) {
    unsigned char* other = self->unk9C;
    if (other != 0) {
        if (g_GameGlobal->m_modeMelee != 0) {
            float rand = randf__Fv();
            switch (self->unk1D8) {
            case 0:
                if (rand < lbl_46_rodata_14) {
                    self->unk1D8 = 1;
                } else {
                    self->unk1D8 = 3;
                }
                return;
            case 2:
                switch (self->unk1E1) {
                case 4:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 5;
                    } else {
                        self->unk1D8 = 7;
                    }
                    return;
                case 5:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 7;
                    } else {
                        self->unk1D8 = 5;
                    }
                    return;
                default:
                    if (rand < lbl_46_rodata_14) {
                        self->unk1D8 = 5;
                    } else {
                        self->unk1D8 = 7;
                    }
                    return;
                }
            case 4:
                switch (self->unk1E1) {
                case 5:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 9;
                    } else {
                        self->unk1D8 = 0xB;
                    }
                    return;
                case 6:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 0xB;
                    } else {
                        self->unk1D8 = 9;
                    }
                    return;
                default:
                    if (rand < lbl_46_rodata_14) {
                        self->unk1D8 = 9;
                    } else {
                        self->unk1D8 = 0xB;
                    }
                    return;
                }
            case 6:
                self->unk1D8 = 0xD;
                return;
            case 8:
            case 10:
                switch (self->unk1E2) {
                case 7:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 0xF;
                    } else {
                        self->unk1D8 = 0x11;
                    }
                    return;
                case 8:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 0x11;
                    } else {
                        self->unk1D8 = 0xF;
                    }
                    return;
                default:
                    if (rand < lbl_46_rodata_14) {
                        self->unk1D8 = 0xF;
                    } else {
                        self->unk1D8 = 0x11;
                    }
                    return;
                }
            case 12:
                self->unk1D8 = 0x13;
                return;
            case 14:
            case 16:
                switch (self->unk1E3) {
                case 9:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 0x15;
                    } else {
                        self->unk1D8 = 0x17;
                    }
                    return;
                case 10:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 0x17;
                    } else {
                        self->unk1D8 = 0x15;
                    }
                    return;
                default:
                    if (rand < lbl_46_rodata_14) {
                        self->unk1D8 = 0x15;
                    } else {
                        self->unk1D8 = 0x17;
                    }
                    return;
                }
            case 18:
            case 20:
                switch (self->unk1E3) {
                case 9:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 0x19;
                    } else {
                        self->unk1D8 = 0x1B;
                    }
                    return;
                case 10:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 0x1B;
                    } else {
                        self->unk1D8 = 0x19;
                    }
                    return;
                default:
                    if (rand < lbl_46_rodata_14) {
                        self->unk1D8 = 0x19;
                    } else {
                        self->unk1D8 = 0x1B;
                    }
                    return;
                }
            case 22:
            case 26:
                self->unk1D8 = 0x1D;
                return;
            case 24:
            case 28:
                self->unk1D8 = 0x1F;
                return;
            case 30:
            case 32:
                switch (self->unk1E0) {
                case 2:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 1;
                    } else {
                        self->unk1D8 = 3;
                    }
                    return;
                case 3:
                    if (rand < *(float*)(other + 8)) {
                        self->unk1D8 = 3;
                    } else {
                        self->unk1D8 = 1;
                    }
                    return;
                default:
                    if (rand < lbl_46_rodata_14) {
                        self->unk1D8 = 1;
                    } else {
                        self->unk1D8 = 3;
                    }
                    return;
                }
            }
        }
    }
}

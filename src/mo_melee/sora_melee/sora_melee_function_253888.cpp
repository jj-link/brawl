#include <types.h>
#include <gm/gm_global.h>
#include <if/if_mngr.h>
#pragma force_active on

struct Sub {
    char _00[0x08];
    u8 m_08;
    char _09[0x14 - 0x09];
    u8 m_14;
    char _15[0x98 - 0x15];
    u8 m_98;
    char _99[0x9E - 0x99];
    u8 m_9E;
    char _9F[0xF4 - 0x9F];
    u8 m_F4;
    char _F5[0xFA - 0xF5];
    u8 m_FA;
};

struct Self {
    char _00[0x44];
    Sub* m_44;
    char _48[0x75 - 0x48];
    u8 m_75;
    char _76[0xE0 - 0x76];
    s32 m_E0;
    u32 m_E4;
    char _E8[0x1B8 - 0xE8];
    s32 m_1B8;
    char _1BC[0x1C4 - 0x1BC];
    s32 m_1C4;
    char _1C8[0x258 - 0x1C8];
    u8 m_258;
};

struct Obj1 {
    char _00[0x9C];
    u16 m_9C;
    char _9E[0xB0 - 0x9E];
    u32 m_B0;
    u32 m_B4;
    u32 m_B8;
    u32 m_BC;
    u32 m_C0;
    u32 m_C4;
};

struct Rec {
    char _000[0x34D4];
    u16 m34D4;
    u16 m34D6;
    char _34D8[0x34E4 - 0x34D8];
    u32 m34E4;
    u32 m34E8;
    u32 m34EC;
    u32 m34F0;
    u32 m34F4;
    u32 m34F8;
    char _34FC[0x3530 - 0x34FC];
    u8 m3530[0x18];
    u16 m3548;
    char _354A[0x3554 - 0x354A];
    u32 m3554;
    u32 m3558;
    u32 m355C;
    u32 m3560;
    u32 m3564;
    u32 m3568;
    char _356C[0x3574 - 0x356C];
    u8 m3574[0x18];
};

struct IfC {
    u8 m_00;
    char _01[0x178 - 0x01];
    s32 m_178;
};

extern "C" {
int fn_27_2480CC(int);
void* fn_8004E5D8(void*, int);
int fn_80055398(int);
void fn_80052AC0(int, int);

void fn_27_253888(Self* self) {
    if (self->m_75 != 0) {
        s32 r5 = 0;
        Sub* sub = self->m_44;
        switch (sub->m_14) {
        case 5:
            if (self->m_1C4 >= 0xA) {
                r5 = 1;
            }
            break;
        case 6:
            if (self->m_1C4 >= 0x64) {
                r5 = 1;
            }
            break;
        }
        if (r5 != 0 && g_IfMngr != 0) {
            IfC* c = (IfC*)g_IfMngr->m_ifCenter;
            if ((c->m_00 >> 7) & 1) {
                c->m_178 = 0x78;
            }
        }
    } else {
        Sub* sub = self->m_44;
        Rec* rec;
        u8 r30 = 0;
        s32 r29 = 0;
        u32 kind = ((u32)sub->m_08 >> 2) & 0x3F;
        if (kind == 0xA) {
            if (self->m_1B8 == 1) {
                Obj1* o1 = (Obj1*)fn_8004E5D8(g_GameGlobal, fn_27_2480CC(sub->m_98));
                switch (self->m_44->m_14) {
                case 5:
                    if (self->m_1C4 >= 0xA) {
                        r29 = 1;
                        if (!((o1->m_9C >> 14) & 1) || self->m_E4 < o1->m_B0) {
                            r30 = 1;
                            o1->m_9C |= 0x4000;
                            o1->m_B0 = self->m_E4;
                        }
                    } else if (!((o1->m_9C >> 14) & 1) && o1->m_B0 < (u32)self->m_1C4) {
                        o1->m_B0 = self->m_1C4;
                        r30 = 1;
                    }
                    break;
                case 6:
                    if (self->m_1C4 >= 0x64) {
                        r29 = 1;
                        if (!((o1->m_9C >> 13) & 1) || self->m_E4 < o1->m_B4) {
                            r30 = 1;
                            o1->m_9C |= 0x2000;
                            o1->m_B4 = self->m_E4;
                        }
                        if (self->m_E4 <= 0x2A30 && fn_80055398(0x14) != 0) {
                            fn_80052AC0(0x209, 1);
                        }
                    } else if (!((o1->m_9C >> 13) & 1) && o1->m_B4 < (u32)self->m_1C4) {
                        o1->m_B4 = self->m_1C4;
                        r30 = 1;
                    }
                    break;
                case 7:
                    if (!((o1->m_9C >> 12) & 1) && self->m_E0 == 0) {
                        o1->m_9C |= 0x1000;
                    }
                    if (o1->m_B8 < (u32)self->m_1C4) {
                        o1->m_B8 = self->m_1C4;
                        r30 = 1;
                    }
                    break;
                case 8:
                    if (!((o1->m_9C >> 11) & 1) && self->m_E0 == 0) {
                        o1->m_9C |= 0x800;
                    }
                    if (o1->m_BC < (u32)self->m_1C4) {
                        o1->m_BC = self->m_1C4;
                        r30 = 1;
                    }
                    break;
                case 9:
                    if (o1->m_C0 < (u32)self->m_1C4) {
                        o1->m_C0 = self->m_1C4;
                        r30 = 1;
                    }
                    break;
                case 10:
                    if (o1->m_C4 < (u32)self->m_1C4) {
                        o1->m_C4 = self->m_1C4;
                        r30 = 1;
                    }
                    if (self->m_1C4 >= 0xA && fn_80055398(0x3F) != 0) {
                        fn_80052AC0(0x2A5, 1);
                    }
                    break;
                }
            } else {
                rec = (Rec*)g_GameGlobal->m_record;
                switch (sub->m_14) {
                case 5:
                    if (self->m_1C4 >= 0xA) {
                        r29 = 1;
                        if (!((rec->m34D4 >> 14) & 1) || self->m_E4 < rec->m34E4) {
                            r30 = 1;
                            rec->m34D4 |= 0x4000;
                            rec->m34E4 = self->m_E4;
                        }
                    } else if (!((rec->m34D4 >> 14) & 1) && rec->m34E4 < (u32)self->m_1C4) {
                        rec->m34E4 = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m34D6 |= 0x4000;
                        rec->m3530[0] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3530[1] = self->m_44->m_9E;
                        rec->m3530[2] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3530[3] = self->m_44->m_FA;
                    }
                    break;
                case 6:
                    if (self->m_1C4 >= 0x64) {
                        r29 = 1;
                        if (!((rec->m34D4 >> 13) & 1) || self->m_E4 < rec->m34E8) {
                            r30 = 1;
                            rec->m34D4 |= 0x2000;
                            rec->m34E8 = self->m_E4;
                        }
                        if (self->m_E4 <= 0x2A30 && fn_80055398(0x14) != 0) {
                            fn_80052AC0(0x209, 1);
                        }
                    } else if (!((rec->m34D4 >> 13) & 1) && rec->m34E8 < (u32)self->m_1C4) {
                        rec->m34E8 = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m34D6 |= 0x2000;
                        rec->m3530[4] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3530[5] = self->m_44->m_9E;
                        rec->m3530[6] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3530[7] = self->m_44->m_FA;
                    }
                    break;
                case 7:
                    if (!((rec->m34D4 >> 12) & 1) && self->m_E0 == 0) {
                        rec->m34D4 |= 0x1000;
                    }
                    if (rec->m34EC < (u32)self->m_1C4) {
                        rec->m34EC = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m34D6 |= 0x1000;
                        rec->m3530[8] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3530[9] = self->m_44->m_9E;
                        rec->m3530[10] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3530[11] = self->m_44->m_FA;
                    }
                    break;
                case 8:
                    if (!((rec->m34D4 >> 11) & 1) && self->m_E0 == 0) {
                        rec->m34D4 |= 0x800;
                    }
                    if (rec->m34F0 < (u32)self->m_1C4) {
                        rec->m34F0 = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m34D6 |= 0x800;
                        rec->m3530[12] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3530[13] = self->m_44->m_9E;
                        rec->m3530[14] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3530[15] = self->m_44->m_FA;
                    }
                    break;
                case 9:
                    if (rec->m34F4 < (u32)self->m_1C4) {
                        rec->m34F4 = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m34D6 |= 0x400;
                        rec->m3530[16] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3530[17] = self->m_44->m_9E;
                        rec->m3530[18] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3530[19] = self->m_44->m_FA;
                    }
                    break;
                case 10:
                    if (rec->m34F8 < (u32)self->m_1C4) {
                        rec->m34F8 = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m34D6 |= 0x200;
                        rec->m3530[20] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3530[21] = self->m_44->m_9E;
                        rec->m3530[22] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3530[23] = self->m_44->m_FA;
                    }
                    if (self->m_1C4 >= 0xA && fn_80055398(0x3F) != 0) {
                        fn_80052AC0(0x2A5, 1);
                    }
                    break;
                }
            }
        } else if (kind == 0x10) {
            if (self->m_1B8 == 2) {
                rec = (Rec*)g_GameGlobal->m_record;
                switch (sub->m_14) {
                case 5:
                    if (self->m_1C4 >= 0xA) {
                        r29 = 1;
                        if (!((rec->m3548 >> 14) & 1) || self->m_E4 < rec->m3554) {
                            r30 = 1;
                            rec->m3548 |= 0x4000;
                            rec->m3554 = self->m_E4;
                        }
                    } else if (!((rec->m3548 >> 14) & 1) && rec->m3554 < (u32)self->m_1C4) {
                        rec->m3554 = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m3548 |= 0x20;
                        rec->m3574[0] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3574[1] = self->m_44->m_9E;
                        rec->m3574[2] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3574[3] = self->m_44->m_FA;
                    }
                    break;
                case 6:
                    if (self->m_1C4 >= 0x64) {
                        r29 = 1;
                        if (!((rec->m3548 >> 13) & 1) || self->m_E4 < rec->m3558) {
                            r30 = 1;
                            rec->m3548 |= 0x2000;
                            rec->m3558 = self->m_E4;
                        }
                    } else if (!((rec->m3548 >> 13) & 1) && rec->m3558 < (u32)self->m_1C4) {
                        rec->m3558 = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m3548 |= 0x10;
                        rec->m3574[4] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3574[5] = self->m_44->m_9E;
                        rec->m3574[6] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3574[7] = self->m_44->m_FA;
                    }
                    break;
                case 7:
                    if (!((rec->m3548 >> 12) & 1) && self->m_E0 == 0) {
                        rec->m3548 |= 0x1000;
                    }
                    if (rec->m355C < (u32)self->m_1C4) {
                        rec->m355C = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m3548 |= 0x8;
                        rec->m3574[8] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3574[9] = self->m_44->m_9E;
                        rec->m3574[10] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3574[11] = self->m_44->m_FA;
                    }
                    break;
                case 8:
                    if (!((rec->m3548 >> 11) & 1) && self->m_E0 == 0) {
                        rec->m3548 |= 0x800;
                    }
                    if (rec->m3560 < (u32)self->m_1C4) {
                        rec->m3560 = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m3548 |= 0x4;
                        rec->m3574[12] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3574[13] = self->m_44->m_9E;
                        rec->m3574[14] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3574[15] = self->m_44->m_FA;
                    }
                    break;
                case 9:
                    if (rec->m3564 < (u32)self->m_1C4) {
                        rec->m3564 = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m3548 |= 0x2;
                        rec->m3574[16] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3574[17] = self->m_44->m_9E;
                        rec->m3574[18] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3574[19] = self->m_44->m_FA;
                    }
                    break;
                case 10:
                    if (rec->m3568 < (u32)self->m_1C4) {
                        rec->m3568 = self->m_1C4;
                        r30 = 1;
                    }
                    if (r30 != 0) {
                        rec->m3548 |= 0x1;
                        rec->m3574[20] = fn_27_2480CC(self->m_44->m_98);
                        rec->m3574[21] = self->m_44->m_9E;
                        rec->m3574[22] = fn_27_2480CC(self->m_44->m_F4);
                        rec->m3574[23] = self->m_44->m_FA;
                    }
                    break;
                }
            }
        }
        if (r29 != 0) {
            if (g_IfMngr != 0) {
                IfC* c = (IfC*)g_IfMngr->m_ifCenter;
                if ((c->m_00 >> 7) & 1) {
                    c->m_178 = 0x78;
                }
            }
        }
        self->m_258 = r30;
    }
}
}

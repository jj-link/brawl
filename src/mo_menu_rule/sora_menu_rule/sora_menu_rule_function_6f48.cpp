#include <snd/snd_system.h>
#include <mu/mu_object.h>
#pragma force_active on

struct Objects {
    char pad[0x144];
    MuObject* toggle;
};
struct Menu {
    char pad[0x64c];
    Objects* objects;
    char pad2[0x20];
    u32 column;
    u32 row;
    u8 level;
    char pad3[7];
    u64 mask;
};
extern "C" {
extern float lbl_18_rodata_E8;
extern float lbl_18_rodata_EC;
void fn_18_17B0(Menu*, int, int, float);
void fn_18_75F4(Menu*);
void fn_18_7818(Menu*, int);
u64 fn_803F1798(u32, u32, u32);
}
static inline u32 selection(Menu* self) {
    if (self->row == 0) {
        return 0;
    } else if (self->row == 1) {
        if (self->column == 0) {
            return 1;
        } else {
            return self->column;
        }
    } else {
        u32 r = self->row - 1;
        u32 v = (r * 8) - r;
        return v + self->column;
    }
}

extern "C" int fn_18_6F48(Menu* self, int flags) {
    int changed = 0;
    u32 old = selection(self);
    if (flags & 1) {
        if (self->row == 0) {
            if (self->column > 1) self->row = 7;
            else self->row = 8;
        } else {
            if (self->row == 2 && self->column == 1) self->column = 0;
            self->row--;
        }
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        changed = 1;
    } else if (flags & 2) {
        if (self->row == 8) self->row = 0;
        else if (self->row == 7 && self->column > 1) self->row = 0;
        else self->row++;
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        changed = 1;
    } else if (flags & 4) {
        if (self->row == 0) {
            if ((s8)self->level != 0) {
                self->level--;
                fn_18_17B0(self, 0x1f, 0x11, (float)(s8)self->level);
                changed = 1;
                self->column = (s8)self->level + 3;
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            }
        } else {
            if (self->row == 1 && self->column == 2) self->column = 0;
            else if (self->column == 0) {
                if (self->row == 8) self->column = 1;
                else self->column = 6;
            } else self->column--;
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            changed = 1;
        }
    } else if (flags & 8) {
        if (self->row == 0) {
            if ((int)self->level != 3) {
                self->level++;
                fn_18_17B0(self, 0x1f, 0x11, (float)(s8)self->level);
                changed = 1;
                self->column = (s8)self->level + 3;
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            }
        } else {
            if (self->row == 1 && self->column == 0) self->column = 2;
            else if (self->column == 6) self->column = 0;
            else if (self->row == 8 && self->column == 1) self->column = 0;
            else self->column++;
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            changed = 1;
        }
    } else if (flags & 0x200) {
        if (self->row == 0) {
            self->row = 1;
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            changed = 1;
        } else if (old == 1) {
            if (lbl_18_rodata_E8 == self->objects->toggle->m_modelAnim->m_anmObjMatClrRes->GetFrame()) {
                g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                self->mask = 0x1ffffffffffffULL;
                for (u32 i = 0; i < 0x31; i++) {
                    fn_18_17B0(self, i + 0x20, 0x10, lbl_18_rodata_E8);
                }
                fn_18_17B0(self, 0x51, 0x10, lbl_18_rodata_EC);
            } else {
                g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                self->mask = 0;
                for (u32 i = 0; i < 0x31; i++) {
                    fn_18_17B0(self, i + 0x20, 0x10, lbl_18_rodata_EC);
                }
                fn_18_17B0(self, 0x51, 0x10, lbl_18_rodata_E8);
            }
            fn_18_75F4(self);
        } else {
            u32 bit = old - 2;
            changed = 1;
            u64 flag = fn_803F1798(0, 1, bit);
            if (self->mask & flag) {
                g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                fn_18_17B0(self, bit + 0x20, 0x10, lbl_18_rodata_EC);
            } else {
                g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                fn_18_17B0(self, bit + 0x20, 0x10, lbl_18_rodata_E8);
            }
            self->mask ^= flag;
            u64 active = self->mask & 0x1ffffffffffffULL;
            if (active == 0) {
                fn_18_17B0(self, 0x51, 0x10, lbl_18_rodata_E8);
            } else if (active == 0x1ffffffffffffULL) {
                fn_18_17B0(self, 0x51, 0x10, lbl_18_rodata_EC);
            }
        }
    }
    if (changed) {
        u32 current = selection(self);
        if (old == current) fn_18_7818(self, 0);
        else fn_18_7818(self, 1);
        fn_18_75F4(self);
        return 1;
    }
    return 0;
}

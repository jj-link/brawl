#include <types.h>
#pragma force_active on

struct WatchMenu {
    u8 pad0[0x50C];
    s32 unk50C;
    u8 pad510[4];
    s32 unk514;
    u8 pad518[8];
    s32 unk520;
    u8 pad524[0x6E8 - 0x524];
    u16 src6E8[0x64];
    u16 count7B0;
    u16 buf7B2[0xC8];
    s32 writeIdx944;
    u8 pad948[4];
    s32 count94C;
    u8 pad950[0xD44 - 0x950];
    s32 unkD44;
    s32 unkD48;
    s32 unkD4C;
    f32 unkD50;
    u8 padD54[4];
    u8 unkD58;
    u8 padD59[0xD6C - 0xD59];
    s32 unkD6C;
    s32 unkD70;
};

extern "C" {

s32 playSE__9sndSystemF5SndIDiiii(void* arg, s32 id, s32 a, s32 b, s32 c, s32 d);
extern void* g_sndSystem;
extern f32 lbl_15_rodata_210;
extern f32 lbl_15_rodata_4;

void fn_15_47E8(WatchMenu* self) {
    u16 v;
    u16* p;
    int i;
    s32 val;

    if (self->unkD58) {
        val = self->unkD48 + self->unk50C;
        self->unkD4C = val;
        if (val > 0x270F) {
            self->unkD4C = 0x270F;
        }

        p = (u16*)self;
        for (i = 0; i < self->count7B0; i++) {
            v = p[0x374];
            if (self->count94C < 0xC8) {
                self->buf7B2[self->writeIdx944] = v;
                self->writeIdx944 = self->writeIdx944 + 1;
                if (self->writeIdx944 >= 0xC8) {
                    self->writeIdx944 = 0;
                }
                self->count94C = self->count94C + 1;
            }
            p += 1;
        }

        val = self->unkD48;
        if (val > 0x64) {
            val = 0x64;
        }
        if (val > 0 && (u32)(self->unkD6C + 0x10000) == 0xFFFF) {
            self->unkD6C = playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1EF8, -1, 0, 0, -1);
        }
        self->unkD44 = val;
    } else {
        s32 r4;
        if (self->unk514 == 0) {
            r4 = 0;
        } else {
            r4 = self->unk520;
        }
        val = self->unk50C - r4;
        self->unkD4C = val;
        if (val < 0) {
            self->unkD4C = 0;
        }
        if ((u32)(self->unkD70 + 0x10000) == 0xFFFF) {
            self->unkD70 = playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1EFA, -1, 0, 0, -1);
        }
    }

    s32 diff = self->unkD4C - self->unk50C;
    s32 s = diff >> 31;
    diff = (s ^ diff) - s;
    if (diff > 0x78) {
        self->unkD50 = (f32)diff / lbl_15_rodata_210;
    } else {
        self->unkD50 = lbl_15_rodata_4;
    }
}

}

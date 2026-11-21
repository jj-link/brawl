#include <types.h>
#include <snd/snd_system.h>
#pragma force_active on

struct Info {
    char pad[0x20];
    s32 f20;
    char pad1[0x4];
    s32 f28;
};

struct Ctx {
    char pad0[0x44];
    Info* f44;
    char pad48[0x10];
    s32 f58;
    s32 f5c;
    s32 f60;
    char pad64[0x4];
    s32 f68;
    s32 f6c;
    char pad70[0x4];
    s32 f74;
    s32 f78;
    char pad7c;
    u8 f7d;
    u8 f7e;
    char pad7f;
};

extern "C" u32 fn_80077DA0(sndSystem*, s32);
extern "C" void fn_80075F1C(sndSystem*, s32, s32);

extern "C" void fn_27_10FE78(Ctx* self) {
    if (self->f60 >= self->f44->f28) {
        if (self->f58 < self->f44->f20) {
            self->f58 = self->f58 + 1;
        }
    } else {
        if (self->f74 != -1) {
            if (fn_80077DA0(g_sndSystem, self->f74) == 0) {
                s32 n = self->f60 + 1;
                self->f60 = n;
                if (n < self->f44->f28) {
                    if (self->f7d == 1) {
                        self->f7d = 0;
                        self->f58 = 0;
                        self->f60 = self->f44->f28;
                        if (self->f74 != -1 && fn_80077DA0(g_sndSystem, self->f74) == 1U) {
                            fn_80075F1C(g_sndSystem, self->f74, 0);
                        }
                        self->f74 = -1;
                        if (self->f7e == 1) {
                            if (self->f68 != -1 && fn_80077DA0(g_sndSystem, self->f68) == 1U) {
                                fn_80075F1C(g_sndSystem, self->f68, 0);
                            }
                            self->f68 = -1;
                            self->f68 = g_sndSystem->playSE((SndID)0x1A, self->f78, 0, 0, -1);
                            self->f7e = 0;
                        }
                    } else {
                        self->f74 = g_sndSystem->playSE((SndID)self->f5c, self->f78, 0, 0, -1);
                    }
                } else {
                    self->f58 = 0;
                    if (self->f74 != -1) {
                        if (fn_80077DA0(g_sndSystem, self->f74) == 1U) {
                            fn_80075F1C(g_sndSystem, self->f74, 0);
                        }
                    }
                    self->f74 = -1;
                    if (self->f6c != -1) {
                        if (fn_80077DA0(g_sndSystem, self->f6c) == 1U) {
                            fn_80075F1C(g_sndSystem, self->f6c, 0);
                        }
                    }
                    self->f6c = -1;
                    self->f6c = g_sndSystem->playSE((SndID)0x1D, self->f78, 0, 0, -1);
                }
            }
        }
    }
}
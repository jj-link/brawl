#include <gm/gm_global.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern "C" {
extern void* lbl_805A01D8;
extern u8 lbl_8045D8A0[];
extern f32 lbl_805A28E8;
extern f32 lbl_805A28EC;
extern f32 lbl_805A28F0;
extern f32 lbl_805A28F4;
extern f32 lbl_805A28F8;
extern f32 lbl_805A28FC;
extern f32 lbl_805A2900;
s32 fn_8007923C(void*, s32, s32, s32);
void fn_801E1D80(s64, OSCalendarTime*);
f32 randf__Fv();
}

struct MeleeView {
    char pad[8];
    u8 gameMode : 6;
    u8 rest : 2;
};

static inline void pick3(u8* mode, f32 p0, f32 p1, f32 p2) {
    f32 total = p2 + (p0 + p1);
    f32 r = total * randf__Fv();
    if (r < p0) {
        *mode = 0;
    } else if (r < (p0 + p1)) {
        *mode = 1;
    } else {
        *mode = 2;
    }
}

extern "C" void fn_8010F960(s32 kind, u8* mode, s32* id, s32 force) {
    if (force == 0) {
        *id = 0;
        for (s32 i = 0; i < 0x33; i++) {
            if (kind == (s32)lbl_8045D8A0[i * 2]) {
                u8 k = lbl_8045D8A0[i * 2 + 1];
                s32 r = fn_8007923C(lbl_805A01D8, k, 0, 0);
                if (r >= 0) {
                    *id = (k << 24) | r;
                }
                break;
            }
        }
    }

    switch (kind) {
    case 0x15: {
        f32 b;
        f32 a = lbl_805A28E8;
        f32 c = lbl_805A28EC;
        b = c + (a + a);
        f32 r = b * randf__Fv();
        if (r < a) {
            *mode = 0;
        } else if (r < (a + a)) {
            *mode = 1;
        } else {
            *mode = 2;
        }
        break;
    }
    case 0x5: {
        if (g_GameGlobal->m_modeMelee != 0 && ((MeleeView*)g_GameGlobal->m_modeMelee)->gameMode == 7) {
            *mode = 0;
        } else {
            u16 stage = *(u16*)g_GameGlobal->m_stageData;
            u16 newStage;
            switch (stage) {
            case 2:
                newStage = 3;
                *mode = 1;
                break;
            case 3:
                newStage = 1;
                *mode = 0;
                break;
            default:
                if (randf__Fv() < lbl_805A28F0) {
                    *mode = 0;
                    if (stage == 1) {
                        newStage = 2;
                    } else {
                        newStage = 1;
                    }
                } else {
                    newStage = 3;
                    *mode = 1;
                }
                break;
            }
            u8 sub;
            switch (*mode) {
            case 0:
                sub = 4;
                break;
            case 1:
                sub = 5;
                break;
            }
            s32 r = fn_8007923C(lbl_805A01D8, sub, 0, 0);
            if (r >= 0) {
                *id = (sub << 24) | r;
            }
            *(u16*)g_GameGlobal->m_stageData = newStage;
        }
        break;
    }
    case 0x21: {
        if (*mode == 0x10) {
            *mode = 5;
            break;
        }
        OSCalendarTime cal;
        fn_801E1D80(OSGetTime(), &cal);
        s32 hour = cal.hour;
        s32 min = cal.min;
        s32 wday = cal.wday;
        if (hour >= 0x17 || hour <= 3) {
            *mode = 6;
        } else if (hour >= 4 && hour <= 7) {
            *mode = 0;
        } else if (hour >= 8 && hour <= 0xF) {
            *mode = 1;
        } else if (hour >= 0x10 && hour <= 0x12) {
            *mode = 2;
        } else {
            *mode = 3;
        }
        if (wday == 6) {
            if (hour == 0x13 && min >= 0x1E) {
                *mode = 4;
            } else if (hour >= 0x14 && hour <= 0x18) {
                if (hour < 0x17) {
                    *mode = 5;
                } else {
                    *mode = 7;
                }
            }
        }
        u8 t = *mode;
        if (t == 5 || t == 7) {
            f32 r = randf__Fv();
            if (r < lbl_805A28F4) {
                *id = 0xFF0027B9;
            } else if (r < lbl_805A28F8) {
                *id = 0xFF0027BA;
            } else if (r < lbl_805A28F0) {
                *id = 0xFF0027BB;
            } else if (r < lbl_805A28FC) {
                *id = 0xFF0027BC;
            } else if (r < lbl_805A2900) {
                *id = 0xFF0027BD;
            } else {
                *id = 0xFF0027BE;
            }
        }
        break;
    }
    case 0x22: {
        f32 b;
        f32 a = lbl_805A28F0;
        b = a + (a + a);
        f32 r = b * randf__Fv();
        if (r < a) {
            *mode = 0;
        } else if (r < (a + a)) {
            *mode = 1;
        } else {
            *mode = 2;
        }
        break;
    }
    case 0x34:
        *id = 0xFF002708;
        break;
    case 0x35: {
        void* t = g_GameGlobal->m_stageEditData;
        *mode = ((u8*)t)[0x14];
        *id = *(u16*)((u8*)t + 0x18) | 0xFF000000;
        break;
    }
    case 0x36:
        *id = 0xFF002707;
        break;
    case 0x37:
        *id = 0xFF0026FF;
        *mode = 0;
        break;
    case 0x38:
        *id = 0xFF002712;
        break;
    }

    if (force != 0) {
        *id = force | 0xFF000000;
    }
}

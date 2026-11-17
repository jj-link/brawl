#include <mv/mv_movie_player.h>
#include <gf/gf_application.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on

extern "C" {
void fn_80036ED0(void* self);
void fn_8003718C(void* self);
void fn_80037244(void* self);
void fn_80076860(void* snd, int arg);
void fn_80076A6C(void* snd, int arg);
void fn_8026F614(void);
}

extern "C" void* g_gfPadSystem;
extern "C" void* g_sndSystem;
extern "C" u8 lbl_804955D4[];
extern "C" u8 lbl_804955D5[];

extern "C" void fn_80036C5C(void* arg0) {
    u8* self = (u8*)arg0;
    s32 var_r4;
    s32 var_r3;
    s32 var_r4_3;
    s32 temp_r4_3;
    u32 var_r5_2;
    s32 var_r3_2;
    u8 var_r4_4;
    u32 x = *(u32*)(self + 0xB0);

    if (((s32)((x << 4) & 0xF8000000) >> 28) == 1) {
        if ((x >> 12) & 0x7F) {
            var_r4 = 0;
            if (((self[0xB1] >> 4) & 1) || *(s32*)(self + 0x9C) != 0) {
                var_r4 = 1;
            }
            if (var_r4 == 0) {
                goto dec;
            }
        }
        *(s32*)(self + 0xB4) = 2;
        goto cd4;
dec:
        if (*(s32*)(self + 0xB4) != 0) {
            *(s32*)(self + 0xB4) -= 1;
        }
cd4:

        if (lbl_804955D4[0] != 0) {
            var_r4 = 0;
            if (((self[0xB1] >> 4) & 1) || *(s32*)(self + 0x9C) != 0) {
                var_r4 = 1;
            }
            if (var_r4 == 0) {
                fn_8026F614();
            }
        }

        var_r4 = 0;
        if (((self[0xB1] >> 4) & 1) || *(s32*)(self + 0x9C) != 0) {
            var_r4 = 1;
        }
        lbl_804955D4[0] = (u8)var_r4;
        fn_80036ED0(arg0);

        var_r3 = 0;
        if (((self[0xB1] >> 4) & 1) || *(s32*)(self + 0x9C) != 0) {
            var_r3 = 1;
        }
        if (var_r3 == 0 && !((((u8*)arg0)[0xB1] >> 3) & 1) && ((*(u8*)((u8*)g_gfPadSystem + 0x34) >> 1) & 1)) {
            fn_8003718C(arg0);
        }
        if ((self[0xB1] >> 4) & 1) {
            fn_80037244(arg0);
        }

        var_r4_3 = 0;
        if (((self[0xB1] >> 4) & 1) || *(s32*)(self + 0x9C) != 0) {
            var_r4_3 = 1;
        }
        g_gfApplication->unkE8[5] = (u8)__rlwimi(g_gfApplication->unkE8[5], var_r4_3, 5, 26, 26);

        temp_r4_3 = (self[0xB1] >> 4) & 1;
        var_r5_2 = 1;
        if (temp_r4_3 == 0 && *(s32*)(self + 0x9C) == 0) {
            var_r5_2 = 0;
        }
        if (lbl_804955D5[0] != var_r5_2) {
            var_r3_2 = 0;
            if (temp_r4_3 != 0 || *(s32*)(self + 0x9C) != 0) {
                var_r3_2 = 1;
            }
            if (var_r3_2 != 0) {
                fn_80076860(g_sndSystem, 0);
                if (mvMoviePlayer::getInstance() != 0) {
                    if (!mvMoviePlayer::getInstance()->isPause()) {
                        mvMoviePlayer::getInstance()->setPause();
                        self[0xC1] = 1;
                    }
                }
            } else {
                fn_80076A6C(g_sndSystem, 0);
                if (mvMoviePlayer::getInstance() != 0 && self[0xC1] != 0) {
                    mvMoviePlayer::getInstance()->resetPause();
                    self[0xC1] = 0;
                }
            }
        }

        var_r4_4 = 0;
        if (((self[0xB1] >> 4) & 1) || *(s32*)(self + 0x9C) != 0) {
            var_r4_4 = 1;
        }
        lbl_804955D5[0] = var_r4_4;
    }
}

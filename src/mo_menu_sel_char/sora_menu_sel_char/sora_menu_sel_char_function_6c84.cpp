#include <types.h>
#include <gm/gm_global.h>
#include <mu/selchar/mu_selchar.h>
#include <mu/selchar/mu_selchar_player_area.h>
#include <snd/snd_system.h>

#pragma force_active on

struct Vec2 {
    float x;
    float y;
};

extern "C" {
void fn_10_1BF94(void*);
Vec2 fn_10_1BC38(void*);
int fn_10_1C514(void*);
int fn_10_EAF4(void*, Vec2*);
void fn_10_1469C(void*, int);
int fn_10_DA54(void*, int);
void fn_10_D540(void*, int, int);
void fn_10_EF24(void*, int, int);
void fn_10_D9B8(void*, int);
int fn_10_12010(void*, int);
void fn_10_FBD4(void*, int, int);
int fn_10_C48C(void*, int);
void fn_10_B2A4(void*, int, int, int);
int fn_10_1C3E0(void*);
}

extern "C" void fn_10_6C84(void* self, int idx) {
    void* sub;
    void* area = *(void**)((u8*)self + idx * 4 + 0x44);
    sub = *(void**)((u8*)area + 0x1AC);
    fn_10_1BF94(sub);
    if (*(int*)((u8*)area + 0x1B4) != 0 &&
        *(int*)area == 0 &&
        *(int*)((u8*)sub + 0x18) != 1) {
        Vec2 pos;
        pos = fn_10_1BC38(sub);
        int n;
        if (fn_10_1C514(sub) == 1) {
            n = fn_10_EAF4(self, &pos);
        } else {
            n = 0x28;
        }
        if (n != *(int*)((u8*)area + 0x1B8)) {
            fn_10_1469C(area, n);
            if (n != 0x28) {
                fn_10_D540(self, fn_10_DA54(self, n), 3);
            }
            fn_10_EF24(self, n, fn_10_1C3E0(sub));
            if (n != 0x29 && n != 0x28) {
                fn_10_D9B8(self, n);
            }
            if (idx == 0 && (s32)((unsigned char*)g_GameGlobal->m_selCharData)[4] == 4) {
                void* first = *(void**)((u8*)self + 0x44);
                sub = *(void**)((u8*)area + 0x1BC);
                int result = fn_10_12010(first, *(int*)((u8*)first + 0x1B8));
                fn_10_FBD4(self, result, (int)sub);
            }
            u8 flag;
            int r = fn_10_C48C(self, (s32)((unsigned char*)g_GameGlobal->m_selCharData)[4]);
            if (&flag != NULL) {
                flag = r != 0;
            }
            int var;
            if (flag == 0) {
                var = 0;
            } else if (*(u8*)((u8*)self + 0x5FC) != 0) {
                s32 k = (s32)((unsigned char*)g_GameGlobal->m_selCharData)[4];
                int ok;
                if (k == 8 || k == 0xE) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok != 0 && (u32)idx <= 1 && *(int*)((u8*)self + 0x600) == 1) {
                    var = 1;
                } else {
                    var = 0;
                }
            } else {
                var = (s32)(idx <= 0);
            }
            if (var != 0) {
                fn_10_B2A4(self, idx, n, *(int*)((u8*)self + 0x5E0));
            }
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        }
    }
}

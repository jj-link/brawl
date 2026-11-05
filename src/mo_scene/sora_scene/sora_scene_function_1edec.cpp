#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" {
void fn_38_4B8(void* task);
void fn_40_3DDD4(void* self);
void* fn_29_0(void* args, s32 heap, s32 fileHeap);
void* fn_40_3DDEC(void* args, s32 a, s32 b);
void fn_800741EC(void* snd, s32 a, s32 b);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int kind);
int getFighterColorFileNo__6muMenuFiii(int kind, int costume);
extern void* lbl_1_bss_1790;
extern float lbl_1_rodata_9C0;
}

struct Args4 { s32 a; s32 b; s32 c; s32 d; };
struct Args7 { s32 a; s32 b; s32 c; s32 d; s32 e; s32 f; s32 g; };

struct Sub {
    u8 pad00[0x58];
    s32 w58;
    u8 pad5C[4];
    s32 w60;
    u8 pad64[4];
    u8 b68;
    u8 pad69;
    u8 b6A;
};

struct Self {
    u8 pad00[0x0C];
    s32 mode;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    u8 f24;
    u8 f25;
    u8 pad26[2];
    s32 f28;
    s32 f2C;
    s32 f30;
    void* f34;
    void* f38;
    void* f3C;
    u8 pad40[0x18];
    Sub* f58;
    u8 pad5C[5];
    u8 f61;
    u8 f62;
};

extern "C" void fn_1_1EDEC(void* arg0) {
    Self* self = (Self*)arg0;
    if (self->f3C != 0) {
        fn_38_4B8(self->f3C);
    }
    if (self->mode != 0) {
        fn_40_3DDD4(lbl_1_bss_1790);
        if (self->mode == 1) {
            Args4 a;
            a.a = self->f18;
            a.b = self->f10;
            a.c = self->f14;
            a.d = self->f30;
            self->f34 = fn_29_0(&a, 0x2A, 0x2B);
        } else if (self->mode == 2) {
            Args7 a = {0, 0, 0, 0, 0, 0, 0};
            a.a = self->f1C;
            a.b = self->f20;
            a.d = self->f10;
            a.e = self->f14;
            a.g = self->f30;
            if (gfSceneManager::getInstance()->m_memoryLayout == 2) {
                ((u8*)&a)[10] = 1;
            }
            self->f38 = fn_40_3DDEC(&a, 0x2A, 0x2B);
        }
        self->f28 = 6;
    } else if (self->f24 != 0) {
        if (self->f25 != 0) {
            s32 var = 0;
            u8* adv = (u8*)g_GameGlobal->m_advData;
            u8* mm = (u8*)g_GameGlobal->m_modeMelee;
            u8 kind = adv[0x2B9];
            mm[0x98] = kind;
            mm[0x99] = var;
            s32 ret = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
            var = (ret == 0x28) ? 0 : getFighterColorFileNo__6muMenuFiii(ret, 0);
            mm[0x9D] = var;
            var = 0;
            mm[0x9E] = var;
            if ((adv[0x4924] >> 5) & 1) {
                u8 kind2 = adv[0x2B9];
                mm[0xF4] = kind2;
                mm[0xF5] = var;
                s32 ret2 = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind2);
                var = (ret2 == 0x28) ? 0 : getFighterColorFileNo__6muMenuFiii(ret2, 1);
                mm[0xF9] = var;
                mm[0xFA] = 1;
            }
        }
        self->f18 = 0xFFFF;
        Args4 b;
        b.a = 0xFFFF;
        b.b = self->f10;
        b.c = self->f14;
        b.d = self->f30;
        self->f34 = fn_29_0(&b, 0x2A, 0x2B);
        self->f62 = 1;
        self->f28 = 6;
    } else {
        self->f28 = 7;
    }
    Sub* s = self->f58;
    if (s != 0 && s->b68 != 0 && self->f61 == 0) {
        g_sndSystem->setBGMVol(false, lbl_1_rodata_9C0 * (float)s->b6A);
        fn_800741EC(g_sndSystem, self->f58->w58, self->f58->w60);
        self->f61 = 1;
    }
}

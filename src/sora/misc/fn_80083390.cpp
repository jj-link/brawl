#include <gf/gf_slow_manager.h>
#include <gm/gm_global.h>
#pragma force_active on

struct Work {
    char pad[0x20];
    void* p20;
    int n24;
    u32 flags28;
    void* p2C;
    int n30;
    u32 flags34;
    int unk38;
    u8 slow;
    u8 unk3D;
    char pad3E[2];
    int mode;
    float fraction;
    float rate;
    int divisor;
    u32 raw34() const { return flags34; }
    u32 raw28() const { return flags28; }
};

extern "C" {
u32 fn_8004E96C(GameGlobal*);
u32 fn_8004E958(GameGlobal*);
void fn_80089224(Work*);
void fn_800851C8(Work*, int, int, int, int, int, int, int, u8, u8, u8, u8);
void fn_8027EABC(void*, void*, u32, int);
extern void* lbl_805A0EC8;
}
extern const float lbl_805A1BB8;
extern const float lbl_805A1BBC;

extern "C" void fn_80083390(Work* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
    u8 a8, u8 a9, u8 a10, int a11, int a12, int a13, int a14, u8 a15)
{
    if (gfSlowManager::getSlowRate() != 1) {
        self->slow = 1;
        self->mode = 1;
        if (fn_8004E96C(g_GameGlobal) == 1) {
            self->mode = 1;
        } else if (fn_8004E958(g_GameGlobal) == 1) {
            self->mode = 0;
        } else {
            self->mode = 2;
        }
        self->rate = lbl_805A1BBC / (float)gfSlowManager::getSlowRate();
        float frame = g_GameGlobal->getGameFrame();
        self->fraction = frame - (float)(int)frame;
    } else {
        self->fraction = lbl_805A1BB8;
        self->rate = lbl_805A1BBC;
        self->slow = 0;
        self->unk3D = 0;
    }
    if (self->divisor > 1) {
        self->rate /= (float)self->divisor;
    }
    fn_80089224(self);
    fn_800851C8(self, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a15);
    if (!(self->flags34 & 0x80000000)) {
        fn_8027EABC(lbl_805A0EC8, self->p2C, self->raw34() * 4, 0x15);
    }
    self->p2C = 0;
    self->n30 = 0;
    self->flags34 = (self->flags34 & 0x40000000) | 0x80000000;
    if (!(self->flags28 & 0x80000000)) {
        fn_8027EABC(lbl_805A0EC8, self->p20, self->raw28() * 4, 0x15);
    }
    self->p20 = 0;
    self->n24 = 0;
    self->flags28 = (self->flags28 & 0x40000000) | 0x80000000;
}

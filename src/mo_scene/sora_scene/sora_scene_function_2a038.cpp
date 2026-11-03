#include <types.h>
#include <string.h>
#pragma force_active on

struct Mode {
    u8 pad0[8];
    u8 gameMode : 6;
    u8 low : 2;
    u8 pad9[0x11];
    u16 stage;
    u8 pad1c[4];
    u32 value;
    u8 pad24[0xc];
    u32 w30;
    u32 w34;
    u8 pad38[0x61];
    u8 b99;
    u8 pad9a[7];
    s8 a1;
    u8 pada2[0x53];
    u8 bF5;
    u8 padf6[7];
    s8 fd;
    u8 padfe[0x53];
    u8 b151;
    u8 pad152[0x5b];
    u8 b1ad;
};
struct Adv {
    u8 pad0[0x5f8];
    u16 stage;
    u8 pad5fa[9];
    u8 mode;
    u8 b604;
    u8 b605;
    u8 b606_7 : 1;
    u8 b606_6 : 1;
    u8 b606_5 : 1;
    u8 rest606 : 5;
    u8 b607;
    u8 pad608[0x14];
    u32 value;
    u32 a620;
    u32 a624;
    u32 a628;
    u32 a62c;
    u8 a630[0x20];
    u8 pad650[0x42c8];
    u32 w4918;
    u32 w491c;
    u8 pad4920[4];
    u8 b4924;
};
struct Other {
    u8 pad0[0xb9];
    u8 b0;
    u8 pad1[0x5b];
    u8 b1;
    u8 pad2[0x5b];
    u8 b2;
    u8 pad3[0x5b];
    u8 b3;
};
struct Global {
    u8 pad0[8];
    Mode* mode;
    u8 padc[4];
    Other* other;
    u8 pad14[0x1c];
    Adv* adv;
};
struct Scene {
    u8 pad0[0x12];
    u8 list[10];
    int count;
    u32 value;
};
extern Global* g_GameGlobal;
extern "C" void* fn_80158BE0();
extern "C" void fn_80159B2C(void*, int, int);
extern "C" void fn_801590A0(void*, int, int);
extern "C" void fn_80055998(u16);

extern "C" void fn_1_2A038(Scene* self) {
    Mode* mode = g_GameGlobal->mode;
    Adv* adv = g_GameGlobal->adv;
    mode->gameMode = 6;
    mode->stage = 0x3d;
    adv->stage = 0x3d;
    adv->b604 = 2;
    adv->a62c = 0;
    adv->a628 = 0;
    adv->mode = 6;
    adv->b606_6 = 0;
    if (adv->b606_7) {
        adv->b606_5 = 0;
    } else {
        adv->b606_5 = 1;
    }
    adv->b607 |= 0x30;
    mode->value = self->value;
    adv->value = self->value;
    adv->b4924 |= 4;
    fn_80055998(mode->stage);
    mode->w34 = 0;
    mode->w30 = 0;
    adv->w491c = 0;
    adv->w4918 = 0;
    memset(adv->a630, 0, 0x20);
    Other* o = g_GameGlobal->other;
    mode->b99 = o->b0;
    mode->bF5 = o->b1;
    mode->b151 = o->b2;
    mode->b1ad = o->b3;
    int id;
    int count = self->count;
    u32 value = self->list[count];
    id = value * 2 + 0x100;
    if (value > 3) id = (u8)value * 2 + 0xfe;
    fn_80159B2C(fn_80158BE0(), count, id);
    if (adv->b606_7) fn_801590A0(fn_80158BE0(), 0x11d, 1);
    if (self->count < 10) {
        switch (self->list[self->count]) {
        default: adv->a620 = 0x5c000100; break;
        case 1: adv->a620 = 0x5c010100; break;
        case 2: adv->a620 = 0x5c020100; break;
        case 3: adv->a620 = 0x5c030100; break;
        case 4: adv->a620 = 0x5c040100; break;
        case 5: adv->a620 = 0x5c050100; break;
        case 6: adv->a620 = 0x5c060100; break;
        case 7: adv->a620 = 0x5c070100; break;
        case 8: adv->a620 = 0x5a010100; break;
        case 9: adv->a620 = 0x5a020100; break;
        case 10: adv->a620 = 0x5c080100; break;
        }
    }
    u32 c = self->list[self->count];
    if (c == 7 || c == 9) {
        mode->a1 = -1;
        mode->fd = -1;
    } else {
        mode->a1 = 1;
        mode->fd = 1;
    }
    adv->a624 = adv->a620;
}

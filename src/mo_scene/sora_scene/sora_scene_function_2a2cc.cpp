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
    u64 items;
    u8 pad38[0x69];
    bool a1;
    u8 pada2[0x5b];
    bool fd;
};
struct Adv {
    u8 pad0[0x5f8];
    u16 stage;
    u8 pad5fa[9];
    u8 mode;
    u8 b604;
    u8 b605;
    u8 b606 : 1;
    u8 rest606 : 7;
    u8 pad607[0x15];
    u32 value;
    u32 a620;
    u32 a624;
    u32 a628;
    u32 a62c;
    u8 a630[0x20];
    u8 pad650[0x42d4];
    u8 unusedFlags : 5;
    u8 flag : 1;
    u8 lowFlags : 2;
};
struct Global {
    u8 pad0[8];
    Mode* mode;
    u8 padc[0x24];
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

extern "C" void fn_1_2A2CC(Scene* self) {
    Mode* mode = g_GameGlobal->mode;
    Adv* adv = g_GameGlobal->adv;
    mode->gameMode = 6;
    mode->stage = 0x3d;
    adv->stage = 0x3d;
    adv->b604 = 0;
    adv->a62c = 0;
    adv->a628 = 0;
    adv->mode = 6;
    memset(adv->a630, 0, 0x20);
    int id;
    int count = self->count;
    u32 value = self->list[count];
    id = value * 2 + 0x100;
    if (value > 3) id = (u8)value * 2 + 0xfe;
    fn_80159B2C(fn_80158BE0(), count, id);
    for (id = 0; id < self->count; id++) {
        u8 value = self->list[id];
        if (value > 3) {
            fn_801590A0(fn_80158BE0(), (u8)value * 2 + 0xff, 1);
        } else {
            fn_801590A0(fn_80158BE0(), (u8)value * 2 + 0x101, 1);
        }
    }
    if (adv->b606) fn_801590A0(fn_80158BE0(), 0x11d, 1);
    adv->a620 = 0x5b010100;
    adv->a624 = 0x5b010100;
    mode->value = self->value;
    adv->value = self->value;
    adv->flag = 1;
    mode->a1 = 1;
    mode->fd = 1;
    struct ItemBits {
        u32 unused : 13;
        u32 trophy : 1;
        u32 rest : 18;
        u32 unused2 : 23;
        u32 food : 1;
        u32 rest2 : 8;
    };
    u64 items = 0;
    ((ItemBits*)&items)->food = 1;
    ((ItemBits*)&items)->trophy = 1;
    mode->items = items;
}

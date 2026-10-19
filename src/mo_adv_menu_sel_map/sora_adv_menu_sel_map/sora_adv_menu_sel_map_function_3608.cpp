#include <types.h>
#pragma force_active on

class muMenu {
public:
    static int exchangeGmCharacterKind2Something(int kind);
};

class adv_menu_sel_map_obj {
public:
    u8 pad0[0x2C];
    u8 unk2A : 5;
    u8 unk2B : 1;
    u8 unk2C : 1;
    u8 unk2D : 1;
    u8 pad2E[0xCD4 - 0x2D];
    u32 unkCD4;
    u32 unkCD8;
};

extern "C" void fn_31_3608(adv_menu_sel_map_obj* self, int p2) {
    self->unk2C = 0;
    self->unkCD4 = p2;
    self->unkCD8 = muMenu::exchangeGmCharacterKind2Something(p2) + 1;
}

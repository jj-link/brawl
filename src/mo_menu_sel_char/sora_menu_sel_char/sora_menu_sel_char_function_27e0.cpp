#pragma force_active on
typedef unsigned char u8;

struct SelCharData {
    u8 pad0[4];
    u8 mode;
    u8 pad5[0x29];
    u8 upper : 3;
    u8 value : 3;
    u8 lower : 2;
};

struct SetRule {
    u8 pad0[2];
    u8 type;
    u8 value3;
    u8 value4;
};

struct GameGlobal {
    u8 pad0[0x10];
    SelCharData* selChar;
    u8 pad14[8];
    SetRule* rule;
};

struct Menu {
    u8 pad0[0x5D8];
    int value5D8;
    int value5DC;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_10_27E0(Menu* self) {
    SelCharData* sel = g_GameGlobal->selChar;
    SetRule* rule = g_GameGlobal->rule;

    if ((int)sel->mode == 4) {
        sel->value = self->value5DC;
    } else if ((int)rule->type == 1) {
        rule->value4 = self->value5DC;
    } else {
        rule->value3 = self->value5D8;
    }
}

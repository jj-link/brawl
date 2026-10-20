#pragma force_active on
typedef unsigned char u8;

struct MeleeData {
    u8 pad0[1];
    u8 settings;
    u8 padA[10];
    u8 mode;
};

struct ModeData {
    u8 pad0[8];
    MeleeData data;
};

struct CorpsData {
    u8 difficulty;
    u8 field1;
    u8 field2;
    u8 field3;
    u8 field4;
    u8 flags;
};

struct GameGlobal {
    u8 pad0[8];
    ModeData* mode;
    u8 padC[0x30];
    CorpsData* corps;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_1_36C44() {
    CorpsData* corps = g_GameGlobal->corps;
    MeleeData* mode = &g_GameGlobal->mode->data;
    int count = 0;
    switch (mode->mode) {
    case 5:
        count = 10;
        break;
    case 6:
        count = 100;
        break;
    }
    corps->difficulty = (mode->settings >> 2) & 7;
    corps->field1 = 0;
    corps->field2 = 5;
    corps->field3 = count;
    corps->field4 = 2;
    corps->flags = (corps->flags & ~0x80) | 0x40;
}

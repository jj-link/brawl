#pragma force_active on
struct SceneData {
    unsigned char pad0[0x250];
    int value;
    int pad254;
    int total;
    unsigned char pad25c[0x4fc - 0x25c];
    int extra;
    unsigned char pad500[0x1378 - 0x500];
    unsigned char mode;
};
struct Flags { unsigned char pad[9]; unsigned char bits; };
struct Settings { unsigned char pad[2]; unsigned char kind; };
struct GameGlobal {
    unsigned char pad0[8];
    Flags* flags;
    unsigned char padc[4];
    Settings* settings;
    unsigned char pad14[4];
    SceneData* data;
};
extern "C" {
extern GameGlobal* g_GameGlobal;
int fn_80051514(int, int);
void fn_80051440(int);
void fn_1_35E34() {
    int type = 2;
    SceneData* data = g_GameGlobal->data;
    int value = data->value;
    unsigned int special;
    unsigned int bits = (g_GameGlobal->flags->bits >> 2) & 7;
    if (bits == 2) {
        type = 3;
        value += data->extra;
    }
    special = 0;
    switch (g_GameGlobal->settings->kind) {
    case 4:
    case 5:
        break;
    case 0:
    case 1:
        if (data->mode == 5) special = 1;
        break;
    case 2:
    case 3:
        if (data->mode == 1) special = 1;
        break;
    }
    if (special == 1) {
        type = 0;
        if (bits == 2) type = 1;
    }
    int amount = fn_80051514(type, value);
    if (amount < 1) amount = 1;
    data->total += amount;
    fn_80051440(data->total);
}
}
#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Wifi;

struct Flags {
    u8 top : 2;
    u8 enabled : 1;
    u8 bottom : 5;
};

struct Player {
    u8 character;
    u8 state;
    u8 playerId;
    u8 playerNo;
    u8 stock;
    u8 colorFile;
    u8 color;
    u8 controller;
    u8 startPoint;
    u8 pad9[2];
    u8 team;
    u16 name[6];
    u8 nameIndex;
    u8 pad19[3];
    Flags flags;
    u8 pad1D[3 + 0x3C];
};

struct Mode {
    u8 pad0[9];
    u8 flagTop : 3;
    u8 count : 3;
    u8 flagLow : 2;
    u8 padA[0x5E];
    int selection;
    int other;
    u8 pad70[0x28];
    Player players[4];
};

struct Global {
    u8 pad0[8];
    Mode* mode;
};

struct Scene {
    u8 pad0[0x14];
    int selection;
    int pad18;
    int other;
};

extern "C" {
extern Global* g_GameGlobal;
extern Wifi* g_muWifiInterfaceTask;

int fn_800CB0D8(Wifi*, int);
int fn_800CB4AC(Wifi*, int);
u8 fn_800CB568(Wifi*, int);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(unsigned int);
int getFighterColorFileNo__6muMenuFiii(int, int);
int fn_800CB8F0(Wifi*, int);
int fn_800CB250(Wifi*, int);
void fn_800D3270(Wifi*, int, u16*, u8*);
int fn_800D81AC(Wifi*, int, int*);
void fn_800D2C50(Wifi*, int, u16*);

void fn_1_39F9C(Scene* self) {
    Mode* mode = g_GameGlobal->mode;
    Mode* cursor;
    u8* nameIndex;
    u16* name;
    Flags* flags;
    Wifi* wifi = g_muWifiInterfaceTask;
    int entries[4];
    int* next = entries;
    int tmp;

    int i = 0;
    do {
        if (fn_800CB0D8(wifi, i) != 3) {
            *next++ = i;
        }
        i++;
    } while (i < 4);

    unsigned int selected = entries[self->selection];
    cursor = mode;
    nameIndex = &mode->players[0].nameIndex;
    name = mode->players[0].name;
    flags = &mode->players[0].flags;

    int i2 = 0;
    do {
        cursor->players[0].state = fn_800CB0D8(wifi, i2);
        if (cursor->players[0].state == 0) {
            cursor->players[0].character = fn_800CB4AC(wifi, i2);
            cursor->players[0].team = i2;
            next = (int*)(u32)fn_800CB568(wifi, i2);
            int kind = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(
                cursor->players[0].character);
            int file;

            if (kind == 0x28) {
                file = 0;
            } else {
                file = getFighterColorFileNo__6muMenuFiii(kind, (int)next);
            }

            cursor->players[0].colorFile = file;
            cursor->players[0].color = fn_800CB568(wifi, i2);
            cursor->players[0].playerId = fn_800CB8F0(wifi, i2);
            cursor->players[0].startPoint = i2;
            cursor->players[0].controller = fn_800CB250(wifi, i2);
            cursor->players[0].stock = -(i2 == selected);
            fn_800D3270(wifi, fn_800CB8F0(wifi, i2), name, nameIndex);

            if (cursor->players[0].name[0] == 0) {
                int index = fn_800D81AC(wifi, fn_800CB8F0(wifi, i2), &tmp);
                fn_800D2C50(wifi, (u8)index, name);
            }

            if (cursor->players[0].name[0] == 0) {
                flags->enabled = 0;
            } else {
                flags->enabled = 1;
            }
        } else {
            cursor->players[0].startPoint = 0;
        }

        i2++;
        cursor = (Mode*)((u8*)cursor + sizeof(Player));
        nameIndex += sizeof(Player);
        name = (u16*)((u8*)name + sizeof(Player));
        flags = (Flags*)((u8*)flags + sizeof(Player));
    } while (i2 < 4);

    mode->selection = self->selection;
    mode->other = self->other;
    mode->count = 2;
}
}

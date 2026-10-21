#pragma force_active on

typedef unsigned int u32;
typedef int s32;

struct GameData {
    unsigned char pad[0x624];
    u32 id;
};

struct GameGlobal {
    unsigned char pad[0x30];
    GameData* data;
};

struct Entry {
    u32 id;
    s32 value;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
extern Entry lbl_27_rodata_3CD0[];
extern Entry lbl_27_rodata_3A30[];

s32 fn_27_24175C(void) {
    u32 id = g_GameGlobal->data->id;
    u32 upper = id & 0xFFFF0000;

    if (upper == 0x2A000000) {
        id &= 0xFFFFFF00;
        for (s32 i = 0; lbl_27_rodata_3CD0[i].id != 0xFFFFFFFF; ++i) {
            if (id == (lbl_27_rodata_3CD0[i].id & 0xFFFFFF00)) {
                return lbl_27_rodata_3CD0[i].value;
            }
        }
        return -1;
    }

    for (s32 i = 0; lbl_27_rodata_3A30[i].id != 0xFFFFFFFF; ++i) {
        if (upper == (lbl_27_rodata_3A30[i].id & 0xFFFF0000)) {
            if ((lbl_27_rodata_3A30[i].id & 0xFFFF) == 0) {
                return lbl_27_rodata_3A30[i].value;
            }
            if (id == lbl_27_rodata_3A30[i].id) {
                return lbl_27_rodata_3A30[i].value;
            }
        }
    }
    return -1;
}
}

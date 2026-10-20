#pragma force_active on
extern "C" {
extern const unsigned char lbl_10_rodata_328[];
int fn_10_99B8(unsigned char* self);
int fn_10_C768(unsigned char* self);
}

struct GameGlobalSub {
    unsigned char pad[4];
    unsigned char unk4;
};

struct GameGlobal {
    unsigned char pad[0x10];
    GameGlobalSub* unk10;
};

extern GameGlobal* g_GameGlobal;

int fn_10_C768(unsigned char* self) {
    unsigned char flag = self[0x5d0];
    int id = g_GameGlobal->unk10->unk4;
    const unsigned char* entry = lbl_10_rodata_328 + id * 12;
    unsigned int ret = (entry[4] >> 5) & 7;
    if (flag != 0) {
        ret = 3;
    }
    if (id == 12) {
        if (fn_10_99B8(self) != 0) {
            ret = 0;
        }
    }
    return ret;
}

#pragma force_active on

typedef unsigned int u32;

struct Menu {
    char pad0[0x188];
    int count;
    char pad18C[0x144C - 0x18C];
    unsigned char mode;
};

struct GameData {
    char pad[0x4898];
    u32 unlocked[2];
};

struct GameGlobal {
    char pad[0x30];
    GameData* data;
};

extern "C" {
    extern char __files[];
    extern char lbl_25_data_B50[];
    extern GameGlobal* g_GameGlobal;

    u32 isCharUsable__6muMenuFiii(int);
    u32 exchangeMuCharKindToGmCharacterKind__6muMenuFiii(int);
    int fn_803F86E4(void*, const char*, ...);
    void fn_803FC984();
}

extern "C" void fn_25_37DC(Menu* self, int* output) {
    self->count = 0;

    for (int i = 0; i < 0x23; ++i) {
        if (self->mode == 0) {
            if (isCharUsable__6muMenuFiii(i) == 1) {
                output[self->count] = i;
                self->count++;
            }
        } else {
            u32 kind = exchangeMuCharKindToGmCharacterKind__6muMenuFiii(i);
            GameData* data = g_GameGlobal->data;

            if (kind >= 0x33) {
                fn_803F86E4(__files + 0xA0, lbl_25_data_B50);
                fn_803FC984();
            }

            if (u32((data->unlocked[kind >> 5] & (1 << (kind & 31))) != 0) == 1) {
                output[self->count] = i;
                self->count++;
            }
        }
    }
}

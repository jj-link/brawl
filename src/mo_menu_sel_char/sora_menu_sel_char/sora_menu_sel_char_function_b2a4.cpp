#pragma force_active on

struct GameMode {
    char pad[4];
    unsigned char mode;
};

struct GameGlobal {
    char pad[0x10];
    GameMode* mode;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
extern const int lbl_10_rodata_178[];

const unsigned char* fn_10_C478(int);
int exchangeMuSelchkindToMuCharKind__6muMenuFiii(int);
int fn_10_B398(void*, int, int, int*, int*);
void dispHighScore__13muSelCharTaskFiii(void*, int, int, int);
void fn_10_10384(void*, int);
void fn_10_10398(void*, int);

void fn_10_B2A4(void* self, int index, int kind, int arg3) {
    int score;
    int value;
    int mode = g_GameGlobal->mode->mode;

    fn_10_C478(mode);

    if (mode == 10) {
        mode = 5;
    } else {
        mode = lbl_10_rodata_178[index];
    }

    if (kind >= 0 && kind < 40) {
        int character = exchangeMuSelchkindToMuCharKind__6muMenuFiii(kind);
        int result = fn_10_B398(self, character, arg3, &score, &value);
        dispHighScore__13muSelCharTaskFiii(self, mode, result, score);
    } else {
        fn_10_10384(self, mode);
        value = -1;
    }

    if ((int)g_GameGlobal->mode->mode != 7) {
        fn_10_10398(self, value);
    }
}
}

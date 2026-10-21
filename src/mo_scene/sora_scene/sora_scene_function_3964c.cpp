#pragma force_active on
struct SceneState {
    unsigned char pad0[0x25];
    unsigned char f25;
    unsigned char pad26[0x2B - 0x26];
    unsigned char f2B;
    unsigned char pad2C[0x250 - 0x2C];
    int f250;
    unsigned char pad254[0x258 - 0x254];
    int f258;
    unsigned char pad25C[0x2D1 - 0x25C];
    unsigned char f2D1;
    unsigned char pad2D2[0x2D7 - 0x2D2];
    unsigned char f2D7;
    unsigned char pad2D8[0x4FC - 0x2D8];
    int f4FC;
    unsigned char pad500[0x1378 - 0x500];
    unsigned char f1378;
};

struct GameGlobalState {
    unsigned char pad0[0x18];
    SceneState* scene;
};

extern "C" {
extern GameGlobalState* g_GameGlobal;

int fn_80051514(int, int);
void fn_80051440(int);

void fn_1_3964C(void) {
    SceneState* s = g_GameGlobal->scene;
    int value = 0;
    int count = 0;

    if (((s->f2B >> 4) & 1) && s->f25 == 0) {
        value = s->f250;
        count = 1;
    }
    if (((s->f2D7 >> 4) & 1) && s->f2D1 == 0) {
        count += 1;
        value += s->f4FC;
    }

    if (count > 0) {
        int type = 2;
        if (count >= 2) {
            type = 3;
        }
        if (s->f1378 == 5) {
            type = 0;
            if (count >= 2) {
                type = 1;
            }
        }
        int amount = fn_80051514(type, value);
        if (amount < 1) {
            amount = 1;
        }
        s->f258 += amount;
        fn_80051440(s->f258);
    }
}
}

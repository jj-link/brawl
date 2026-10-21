#pragma force_active on
struct SceneData {
    unsigned char pad0[0x250];
    int value;
    int pad254;
    int total;
    unsigned char pad25C[0x4FC - 0x25C];
    int extra;
    unsigned char pad500[0x1378 - 0x500];
    unsigned char mode;
};

struct GameGlobal {
    unsigned char pad0[0x18];
    SceneData* data;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
extern int lbl_1_bss_1A60;

int fn_80051514(int, int);
void fn_80051440(int);

void fn_1_3422C() {
    SceneData* data = g_GameGlobal->data;
    int type = 2;
    int value = data->value;

    if (lbl_1_bss_1A60 == 2) {
        type = 3;
        value += data->extra;
    }

    if (data->mode == 7) {
        type = 0;
        if (lbl_1_bss_1A60 == 2) {
            type = 1;
        }
    }

    int amount = fn_80051514(type, value);
    if (amount < 1) {
        amount = 1;
    }

    data->total += amount;
    fn_80051440(data->total);
}
}

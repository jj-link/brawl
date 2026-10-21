#pragma force_active on

typedef int s32;
typedef unsigned int u32;

struct Thresholds {
    float values[3];
};

struct Owner {
    char pad0[0x44];
    Thresholds* thresholds;
    char pad48[0x24];
    s32 sound;
    char pad70[8];
    s32 arg;
};

struct SoundEntry {
    s32 a;
    s32 id;
    s32 c;
};

extern "C" {
extern void* g_sndSystem;
extern const float lbl_27_rodata_F3C;
extern const SoundEntry lbl_27_rodata_F18[3];

u32 fn_80077DA0(void*, s32);
void fn_80075F1C(void*, s32, s32);
s32 playSE__9sndSystemF5SndIDiiii(void*, s32, s32, s32, s32, s32);

void fn_27_110540(Owner* self, s32 flag, float value) {
    s32 index = -1;
    Thresholds* thresholds = self->thresholds;

    if (value >= thresholds->values[2]) {
        index = 2;
    } else if (value >= thresholds->values[1]) {
        index = 1;
    } else if (value > lbl_27_rodata_F3C) {
        index = 0;
    }

    if (index != -1) {
        if (flag == 0 && index > 0) {
            --index;
        }

        if (self->sound != -1 &&
            fn_80077DA0(g_sndSystem, self->sound) == 1U) {
            fn_80075F1C(g_sndSystem, self->sound, 0);
        }

        self->sound = -1;
        self->sound = playSE__9sndSystemF5SndIDiiii(
            g_sndSystem, lbl_27_rodata_F18[index].id,
            self->arg, 0, 0, -1);
    }
}
}

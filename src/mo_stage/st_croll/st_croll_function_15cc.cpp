#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct StageData {
    u32 unknown;
    u32 flags;
    u8 padding[0x6AF4 - 8];
    u8 effect;
};

extern "C" {
extern void* g_efScreen;
extern const float lbl_90_rodata_30;

void fn_8005E3C8(void*, const u8*, float);

void fn_90_15CC(StageData* self) {
    if (self->flags & 2) {
        u8 effect = self->effect;
        fn_8005E3C8(g_efScreen, &effect, lbl_90_rodata_30);
        self->flags &= ~2;
    }
}
}

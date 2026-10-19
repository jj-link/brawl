#pragma force_active on
typedef unsigned int u32;

extern "C" {
void fn_12_588(void* self, int value);
void fn_80074ECC(void* snd, u32 flags, float f1, float f2);
void playBGM__9sndSystemFiUlb(void* self, u32 id, u32 param, u32 flag);
extern void* g_sndSystem;
extern const float lbl_12_rodata_60;
}

extern "C" void fn_12_F18(void* self) {
    fn_12_588(self, 4);
    fn_80074ECC(g_sndSystem, 0x2000, lbl_12_rodata_60, lbl_12_rodata_60);
    playBGM__9sndSystemFiUlb(g_sndSystem, 0x2864, 0, 1);
}

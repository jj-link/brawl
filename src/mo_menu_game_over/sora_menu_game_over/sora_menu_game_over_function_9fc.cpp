#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void fn_12_588(void* self, int value);
void fn_80074ECC(void* snd, u32 flags, float f1, float f2);
extern void* g_sndSystem;
extern const float lbl_12_rodata_60;
}

extern "C" void fn_12_9FC(void* self) {
    fn_12_588(self, 1);
    ((u8*)self)[0x124] = 1;
    fn_80074ECC(g_sndSystem, 0x1fff, lbl_12_rodata_60, lbl_12_rodata_60);
}

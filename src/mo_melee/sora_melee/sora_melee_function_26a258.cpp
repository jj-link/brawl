#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;
typedef float f32;

extern "C" {
u32 GetResAnmChrNumEntries__Q34nw4r3g3d7ResFileFv(void*);
void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
void startGimmickSE__9grGimmickFUl(void*, u32);
}

extern "C" const float lbl_27_rodata_4328;

struct Anim {
    char pad[0x0C];
    f32 unkC;
    char pad2[0x4];
    f32 unk14;
};

extern "C" void fn_27_26A258(char* self, u32 arg1) {
    **(u8**)(self + 0x150) = 0;

    u32 n = GetResAnmChrNumEntries__Q34nw4r3g3d7ResFileFv(
        *(void**)(*(char**)(self + 0x48)));

    if (u32(n > 1) == 1) {
        void* p = *(void**)(self + 0x48);
        if (p != 0) {
            unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(
                *(void**)p, *(void**)(*(char**)(self + 0x44)));
        }
    }

    *(u32*)(self + 0x154) = 0;
    *(f32*)(self + 0x158) = lbl_27_rodata_4328;

    Anim* a = *(Anim**)(self + 0x15c);
    a->unkC = a->unkC * a->unk14;

    if (arg1 != 0) {
        startGimmickSE__9grGimmickFUl(self, 1);
    }
}

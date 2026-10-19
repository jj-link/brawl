#pragma force_active on
extern "C" {
void fn_800B753C(void*, float);
float getFrame__16gfModelAnimationFd(void*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
extern const float lbl_24_rodata_10;
extern const float lbl_24_rodata_8;

void fn_24_A2C(void* self) {
    float frame = getFrame__16gfModelAnimationFd(*(void**)(*(char**)((char*)self + 0x48) + 0x14));
    if (frame < lbl_24_rodata_10) {
        fn_800B753C(*(void**)((char*)self + 0x48), lbl_24_rodata_10);
        setUpdateRate__16gfModelAnimationFf(*(void**)(*(char**)((char*)self + 0x48) + 0x14), lbl_24_rodata_8);
    }
}
}

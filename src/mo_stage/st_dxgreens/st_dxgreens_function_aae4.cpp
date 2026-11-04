#pragma force_active on
typedef unsigned int u32;
extern "C" {
u32 getFrameCount__16gfModelAnimationFd(void* anim);
float getFrame__16gfModelAnimationFd(void* anim);
void setFrame__16gfModelAnimationFd(void* anim, double frame);
}
extern float lbl_79_rodata_50;
extern float lbl_79_rodata_54;

extern "C" void fn_79_AAE4(char* self) {
    void* anim = *(void**)(*(char**)(self + 0x48));
    if (anim) {
        unsigned char* p = *(unsigned char**)(self + 0x160);
        if (p[0x1a] == 1) {
            float total = (float)getFrameCount__16gfModelAnimationFd(anim);
            if (getFrame__16gfModelAnimationFd(anim) >= total) {
                setFrame__16gfModelAnimationFd(anim, lbl_79_rodata_54);
            }
        } else {
            setFrame__16gfModelAnimationFd(anim, lbl_79_rodata_50);
        }
    }
}

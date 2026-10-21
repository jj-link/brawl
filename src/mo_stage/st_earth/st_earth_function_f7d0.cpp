#pragma force_active on
extern "C" void setFrame__16gfModelAnimationFd(void*, double);
extern "C" void setUpdateRate__16gfModelAnimationFf(void*, float);
extern "C" const float lbl_66_rodata_1C8[];

extern "C" void fn_66_F7D0(char* self) {
    const float* c = lbl_66_rodata_1C8;
    char* a = *(char**)(*(char**)(self + 0x44));
    if (a != 0) {
        char* anim = *(char**)(*(char**)(self + 0x48));
        if (anim != 0 && *(int*)(a + 0xe8) != 0) {
            unsigned char t = *(unsigned char*)(*(char**)(self + 0x188) + 0xb);
            float f;
            switch (t) {
            case 0:
                f = c[0];
                break;
            case 1:
                f = c[2];
                break;
            case 2:
                f = c[4];
                break;
            case 3:
                f = c[5];
                break;
            default:
                f = c[0];
                break;
            }
            setFrame__16gfModelAnimationFd(anim, f);
            setUpdateRate__16gfModelAnimationFf(anim, c[0]);
        }
    }
}

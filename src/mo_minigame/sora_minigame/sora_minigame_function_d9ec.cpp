#pragma force_active on

class gfModelAnimation;

extern "C" {
void setFrame__16gfModelAnimationFd(void*, double);
void setUpdateRate__16gfModelAnimationFf(void*, float);
void fn_801AF9F4(void*);
void fn_20_DA94(void*);
extern const float lbl_20_rodata_398;
}

struct AnimObj {
    virtual void vf0();
    virtual void vf1(int, int, int);
};

extern "C" void fn_20_D9EC(void* self) {
    unsigned char* base = (unsigned char*)self;
    AnimObj* animObj = *(AnimObj**)(*(void**)(base + 0x38));
    gfModelAnimation* model =
        *(gfModelAnimation**)(*(void**)(base + 0x3C));

    if (animObj == 0 || model == 0) {
        return;
    }

    setFrame__16gfModelAnimationFd(model, *(float*)(base + 0x24));
    setUpdateRate__16gfModelAnimationFf(model, lbl_20_rodata_398);
    fn_801AF9F4(animObj);
    animObj->vf1(1, 0, 0);
    fn_20_DA94(self);
}

#pragma force_active on
typedef struct cmAnimationController {
    unsigned char pad0[0xC];
    void* unkC;
    void* unk10;
} cmAnimationController;

extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);

extern "C" void releaseScnAnmRes__21cmAnimationControllerFv(cmAnimationController* self) {
    if (self->unk10) {
        Destroy__Q34nw4r3g3d6G3dObjFv(self->unk10);
    }
    if (self->unkC) {
        Destroy__Q34nw4r3g3d6G3dObjFv(self->unkC);
    }
    self->unkC = 0;
    self->unk10 = 0;
}

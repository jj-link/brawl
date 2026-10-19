#pragma force_active on
extern "C" {
extern const float lbl_40_rodata_630;

struct grGimmickMotionPath;
void setFrame__19grGimmickMotionPathFf(grGimmickMotionPath* self, float value);
void startMove__19grGimmickMotionPathFv(grGimmickMotionPath* self);
void startGimmickSE__9grGimmickFUl(void* self, unsigned long);
void startGimmickEffect__9grGimmickFUl(void* self, unsigned long);
}

struct Obj {
    unsigned char pad0[0xcc];
    grGimmickMotionPath* motionPath; // 0xcc
    unsigned char pad1[0x94];
    int flag; // 0x164
};

extern "C" void fn_40_330DC(Obj* self) {
    if (self->flag == 0) {
        self->flag = 1;
        setFrame__19grGimmickMotionPathFf(self->motionPath, lbl_40_rodata_630);
        startMove__19grGimmickMotionPathFv(self->motionPath);
        startGimmickSE__9grGimmickFUl(self, 0);
        startGimmickEffect__9grGimmickFUl(self, 0);
    }
}

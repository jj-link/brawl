#pragma force_active on
extern "C" void setFrame__19grGimmickMotionPathFf(void*);

extern "C" void fn_27_26DA78(void* self) {
    void* motionPath = *(void**)((char*)self + 0xCC);
    if (motionPath != 0) {
        setFrame__19grGimmickMotionPathFf(motionPath);
    }
}

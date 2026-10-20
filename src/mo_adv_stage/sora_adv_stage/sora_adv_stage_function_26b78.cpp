#pragma force_active on
extern const float lbl_40_rodata_3E4;

extern "C" {
float getFrame__19grGimmickMotionPathFv(void* self);
void startMove__19grGimmickMotionPathFv(void* self);
void setFrameUpdate__19grGimmickMotionPathFf(void* self, float frame);

void fn_40_26B78(char* self, unsigned char idx) {
    void** arr = (void**)(self + 0x150);
    *(void**)(self + 0xcc) = arr[idx];
    if (getFrame__19grGimmickMotionPathFv(*(void**)(self + 0xcc)) == lbl_40_rodata_3E4) {
        startMove__19grGimmickMotionPathFv(*(void**)(self + 0xcc));
    } else {
        setFrameUpdate__19grGimmickMotionPathFf(*(void**)(self + 0xcc), *(float*)*(void**)(self + 0x160));
    }
}
}

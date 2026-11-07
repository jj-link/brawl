#include <gr/gr_gimmick.h>
#pragma force_active on
extern float lbl_27_data_547E0;
extern "C" void fn_27_26ECCC(grGimmick* self, float value) {
    float c = lbl_27_data_547E0;
    float f = value * c;
    float g = *(float*)((char*)self + 0x64) * f;
    *(unsigned char*)((char*)self + 0x14c) = 1;
    *(float*)((char*)self + 0x158) = g;
    *(float*)((char*)self + 0x15c) = g;
    if (*(int*)((char*)self + 0xa8)) {
        for (int i = 0; i < 5; i++) self->startGimmickSE(i + 3);
    }
    if (*(int*)((char*)self + 0xb0)) {
        for (int i = 0; i < 5; i++) self->startGimmickEffect(i + 3);
    }
}
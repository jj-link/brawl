#include <types.h>
#pragma force_active on

struct FinalAnimationInfo {
    float start;
    float end;
    float rate;
    const char* name;
    unsigned char flags[4];
};

struct PeachFinalInterface {
    void* reserved[0x4c / sizeof(void*)];
    void* model;
};

extern "C" {

void fn_800B3C5C(void*, const FinalAnimationInfo*, int);
extern FinalAnimationInfo lbl_103_data_67D0[];

void fn_103_10CF4(PeachFinalInterface* self, s32 index) {
    fn_800B3C5C(self->model, &lbl_103_data_67D0[index], 1);
}

}

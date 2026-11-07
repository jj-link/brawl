#include <string.h>
#pragma force_active on
extern "C" {
extern char lbl_804659A0[];
extern const float lbl_805A3148;
extern const float lbl_805A314C;
void fn_801EC158(void*);
void* fn_8018B05C(void* self) {
    *(char**)self = lbl_804659A0;
    *(float*)((char*)self + 0x34) = lbl_805A3148;
    *(float*)((char*)self + 0x38) = lbl_805A3148;
    *(float*)((char*)self + 0x3c) = lbl_805A3148;
    *(float*)((char*)self + 0x40) = lbl_805A3148;
    *(float*)((char*)self + 0x44) = lbl_805A314C;
    *(float*)((char*)self + 0x48) = lbl_805A314C;
    *(float*)((char*)self + 0x4c) = lbl_805A314C;
    memset((char*)self + 0x50, 0, 1);
    fn_801EC158((char*)self + 4);
    return self;
}
}
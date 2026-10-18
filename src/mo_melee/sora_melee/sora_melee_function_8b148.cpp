#include <types.h>
#pragma force_active on

struct FnS27 {
    u8 pad[8];
    float f8;
    float fC;
    float f10;
};

extern "C" {
extern const float lbl_27_rodata_BD0;

void fn_27_8B148(FnS27* p) {
    p->f10 = lbl_27_rodata_BD0;
    p->fC = lbl_27_rodata_BD0;
    p->f8 = lbl_27_rodata_BD0;
}
}

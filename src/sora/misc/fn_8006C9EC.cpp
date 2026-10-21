#include <types.h>
#pragma force_active on

class gfHeapManager;

extern "C" void fn_8015E7C4(void*);
extern "C" void free__13gfHeapManagerFPv(gfHeapManager* self);
extern "C" u8 lbl_80497D7C[0x28];
extern gfHeapManager* lbl_805A0178;

extern "C" int fn_8006C9EC(void) {
    fn_8015E7C4(lbl_80497D7C);
    if (lbl_805A0178 != 0) {
        free__13gfHeapManagerFPv(lbl_805A0178);
        lbl_805A0178 = 0;
    }
    return 1;
}

#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_bss_4694[0xC];
extern "C" u8 lbl_27_bss_46AC[4];

extern "C" void fn_27_D2FF0(void* a, s32 b, s32 c);
extern "C" void fn_27_61454(void* a, void* b, void* c, void* d, void* e, void* f);

extern "C" void* fn_111_69F4(void* a, void* b, void* c) {
    void* r29 = a;
    void* r30 = b;
    void* r31 = c;
    fn_27_D2FF0(a, 1, 0);
    fn_27_61454((char*)r29 + 0xac, r30, r29, lbl_27_bss_4694, lbl_27_bss_46AC, r31);
    return r29;
}

#include <types.h>
#pragma force_active on

extern int lbl_804877E8[];

extern "C" void fn_802D5DF8(void* arg0, f32 farg0) {
    ((s16*)arg0)[3] = 1;
    ((u32*)arg0)[2] = 0;
    ((f32*)arg0)[3] = farg0;
    ((int**)arg0)[0] = lbl_804877E8;
}

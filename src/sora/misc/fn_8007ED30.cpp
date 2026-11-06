#include <mv/mv_THPPlayer.h>
#pragma force_active on

extern "C" {
extern int lbl_805A0214;
extern void* lbl_805A022C;
extern unsigned char lbl_805A024C;
extern unsigned char lbl_8049DDD0[];
extern unsigned char lbl_8049DDF0[];
int fn_801F6278(void*, void*);
int fn_801F6708(void*, void*, int, int, int, int);

void fn_8007ED30() {
    if (lbl_805A0214 != 0) {
        fn_801F6278(lbl_8049DDD0, lbl_8049DDF0);
        fn_801F6708(lbl_8049DDF0, lbl_805A022C, 0x20, g_thpObject.unk64, 0, 2);
        lbl_805A024C = 1;
    }
}
}
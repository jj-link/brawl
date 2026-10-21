#include <types.h>
#pragma force_active on

extern "C" void fn_801D50A0();
extern "C" void fn_801F4EAC(int, int);
extern int lbl_8040A8B8[];

extern "C" void fn_8019092C(void* self, int flag) {
    if (flag != 0) {
        fn_801D50A0();
    }
    void* obj = *(void**)self;
    unsigned char val = ((unsigned char*)obj)[0xc];
    fn_801F4EAC((int)((unsigned char*)obj + 0x20), lbl_8040A8B8[val - 1]);
}

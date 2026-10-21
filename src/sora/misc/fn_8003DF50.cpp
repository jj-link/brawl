#include <types.h>
#pragma force_active on

extern "C" void fn_8003F8FC(void* arg);
extern "C" void fn_8003FA14(void* arg, s32 a, s32 b);

extern "C" void fn_8003DF50(s32 arg0, s32 arg1, s32 arg2) {
    void* sp8;
    fn_8003F8FC(&sp8);
    fn_8003FA14(&sp8, arg0, arg2);
}

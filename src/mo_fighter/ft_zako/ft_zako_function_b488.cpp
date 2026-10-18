#include <types.h>
#pragma force_active on

extern "C" int fn_27_1312F8();
extern "C" int fn_27_195DF0(void* object, void* argument);

extern "C" int fn_126_B488(void* object, void* argument) {
    int result = 0;
    if (fn_27_1312F8() != 0 &&
        fn_27_195DF0(*(void**)((char*)object + 0x60), argument) != 0) {
        result = 1;
    }
    return result;
}

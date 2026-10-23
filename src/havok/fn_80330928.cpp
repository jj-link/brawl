#include <types.h>
#pragma force_active on

extern "C" {
void fn_803311A0(void* self, int arg);
int fn_803314B8(void* self);
int fn_80331560(void* self);
int fn_80281AE8(int arg, int name);
}

extern "C" int fn_80330928(u8* self, int arg1, int arg2) {
    int result;
    int name;
    u8* entry;

    if (arg2 != 0) {
        fn_803311A0(self, arg2);
    }

    entry = *(u8**)(self + 0x68);
    if (entry != 0) {
        result = *(int*)(entry + 0x34);
        name = *(int*)(entry + 0x38);
    } else {
        result = fn_803314B8(self);
        name = fn_80331560(self);
    }

    if (arg1 != 0 && name != 0 && fn_80281AE8(arg1, name) != 0) {
        return 0;
    }
    return result;
}

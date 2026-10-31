#include <types.h>
#pragma force_active on

extern s32 fn_8036BB8C(void*, void*, void*);
extern s32 fn_8036C8F4(void*, void*, void*);
extern s32 fn_803704FC(void*, void*, void*);
extern s32 fn_803707AC(void*, void*, void*);
extern s32 fn_80372CAC(void*, void*, void*);

s32 fn_8036EFC0(void* arg, void* self, void* arg2) {
    s32 result = 0;
    s32 state;
    s32* resultPtr = (s32*)((char*)self + 0x1C);

    state = *(s32*)self;
    switch (state) {
    case 0:
        result = fn_8036BB8C(arg, self, arg2);
        break;
    case 1:
        result = fn_803704FC(arg, self, arg2);
        break;
    case 5:
        result = fn_803707AC(arg, self, arg2);
        break;
    case 2:
        result = fn_8036C8F4(arg, self, arg2);
        break;
    case 4:
        result = fn_80372CAC(arg, self, arg2);
        break;
    }

    if (result != 0) {
        *resultPtr = result;
    }
    return result;
}

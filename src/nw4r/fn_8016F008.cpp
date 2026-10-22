#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void fn_8015C144(void*, void*);

extern "C" int fn_8016F008(void* arg0, void* arg1) {
    void* node = fn_8015C1B0(arg0, 0);
    while (node) {
        if (node == arg1) {
            fn_8015C144(arg0, arg1);
            s32 t;
            if (arg1 != 0) {
                t = *(u16*)((char*)arg1 + *(s32*)arg1 + 4);
            } else {
                t = *(s32*)((char*)arg0 + 0xc);
            }
            *(s32*)((char*)arg0 + 0xc) = *(s32*)((char*)arg0 + 0xc) - t;
            return 1;
        }
        node = fn_8015C1B0(arg0, node);
    }
    return 0;
}

#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_13CF0[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void fn_27_90D80(void* self, s16 value);
extern "C" void __dl__FPv(void* p);

extern "C" void* __dt__23soEventManageModuleImplFv(void* p, s16 flag) {
    if (p) {
        char* vtbl = lbl_27_data_13CF0;
        *(char**)p = vtbl;
        *(char**)((char*)p + 0x8) = vtbl + 0xC;
        fn_27_90D80(getInstance__13soEventSystemFv(), *(s16*)((char*)p + 0x10));
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

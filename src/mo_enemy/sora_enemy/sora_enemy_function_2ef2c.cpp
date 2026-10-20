#include <em/wnem/wn_em_resource_module_impl.h>
#pragma force_active on

extern "C" void* fn_41_2374(void* p, short size);
extern "C" void __dl__FPv(void* p);
extern "C" void __dt__22wnemResourceModuleImplFv(void* p, short mode);

extern "C" void* fn_41_2EF2C(wnemResourceModuleImpl* p, short mode) {
    if (p != NULL) {
        __dt__22wnemResourceModuleImplFv((char*)p + 0x18, -1);
        if (p != NULL) {
            fn_41_2374(p, 0);
        }
        if (mode > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

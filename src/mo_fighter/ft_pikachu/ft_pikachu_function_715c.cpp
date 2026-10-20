#include <new>
#pragma force_active on

extern "C" {
void* __dt__20soResourceModuleImplFv(void*, short);
void* fn_98_4B58(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_715C(void* object, short deleting) {
    if (object) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0xC, -1);
        if (object) {
            fn_98_4B58(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

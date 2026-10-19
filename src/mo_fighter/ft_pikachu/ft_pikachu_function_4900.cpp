#include <new>
#pragma force_active on

extern "C" {
void* __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_19FFEC(void*, short);
}

extern "C" void* fn_98_4900(char* object, short deleting) {
    if (object) {
        __dt__19soPostureModuleImplFv(object + 0x3C, short(-1));
        if (object) fn_27_19FFEC(object, short(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

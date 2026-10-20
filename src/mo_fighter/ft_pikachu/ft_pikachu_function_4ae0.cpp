#include <new>
#pragma force_active on

extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_98_4B58(void*, short);

extern "C" void* fn_98_4AE0(void* object, short deleting) {
    if (object) {
        __dt__20soResourceModuleImplFv(static_cast<char*>(object) + 0x18, -1);
        if (object) fn_98_4B58(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

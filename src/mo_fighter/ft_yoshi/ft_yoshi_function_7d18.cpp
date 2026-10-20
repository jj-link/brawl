#include <new>
#pragma force_active on

extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_95_4938(void* p, short n);

extern "C" void* fn_95_7D18(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0xC, -1);
        if (object != 0) {
            fn_95_4938(object, 0);
        }
        if (deleting > 0) {
            ::operator delete(object);
        }
    }
    return object;
}

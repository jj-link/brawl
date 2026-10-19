#include <new>
#pragma force_active on

extern "C" void* __dt__16soStopModuleImplFv(void*, short);

extern "C" void* fn_98_4710(void* object, short deleting) {
    if (object) {
        __dt__16soStopModuleImplFv(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

#include <new>
#pragma force_active on

extern "C" void* fn_98_C168(void*, short);
extern "C" void* fn_98_C034(void*, short);

static inline void destroyBase(void* object) {
    if (object) fn_98_C034(object, short(0));
}

extern "C" void* fn_98_C1C8(void* object, short deleting) {
    if (object) {
        fn_98_C168(static_cast<char*>(object) + 0x1c8, short(-1));
        destroyBase(object);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

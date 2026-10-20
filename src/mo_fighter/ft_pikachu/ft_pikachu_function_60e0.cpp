#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A1B88(void*, short);
void* fn_98_6158(void*, short);
}

static inline void destroyBase(char* object) {
    if (object) fn_98_6158(object, 0);
}

extern "C" void* fn_98_60E0(char* object, short deleting) {
    if (object) {
        fn_27_1A1B88(object + 0xf0, -1);
        destroyBase(object);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

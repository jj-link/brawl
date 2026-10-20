#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A1E70(void*, short);
void* fn_98_5F78(void*, short);
}

static inline void destroyBase(char* object) {
    if (object) fn_98_5F78(object, short(0));
}

extern "C" void* fn_98_5F00(char* object, short deleting) {
    if (object) {
        fn_27_1A1E70(object + 0x190, short(-1));
        destroyBase(object);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

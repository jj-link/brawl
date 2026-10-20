#include <new>
#pragma force_active on

extern "C" void* fn_98_BE3C(void* object, short deleting);
extern "C" void* fn_98_BD08(void* object, short deleting);

static inline void destroySomething(char* object) {
    if (object) fn_98_BD08(object, short(0));
}

extern "C" void* fn_98_BE9C(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_BE3C(object + 0x134, memberDeleting);
        destroySomething(object);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

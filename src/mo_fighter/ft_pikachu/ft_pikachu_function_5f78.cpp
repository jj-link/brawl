#include <new>
#pragma force_active on

extern "C" {
void* fn_27_D2904(void*, short);
void* fn_98_5FF0(void*, short);
}

extern "C" void* fn_98_5F78(char* object, short deleting) {
    if (object) {
        fn_27_D2904(object + 0x154, short(-1));
        if (object) fn_98_5FF0(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

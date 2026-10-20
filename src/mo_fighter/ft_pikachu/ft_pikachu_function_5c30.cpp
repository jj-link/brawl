#include <new>
#pragma force_active on

extern "C" {
void* fn_27_D2904(void*, short);
void* fn_98_5CA8(void*, short);
}

extern "C" void* fn_98_5C30(char* object, short deleting) {
    if (object) {
        fn_27_D2904(object + 0x318, short(-1));
        if (object) fn_98_5CA8(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

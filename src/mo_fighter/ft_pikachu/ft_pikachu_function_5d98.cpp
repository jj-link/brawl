#include <new>
#pragma force_active on

extern "C" void* fn_27_1A1FE4(void*, short);
extern "C" void* fn_98_5E10(void*, short);

extern "C" void* fn_98_5D98(char* object, short deleting) {
    if (object) {
        fn_27_1A1FE4(object + 0x244, short(-1));
        if (object) fn_98_5E10(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

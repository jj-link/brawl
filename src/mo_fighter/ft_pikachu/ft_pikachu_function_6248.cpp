#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A1E70(void*, short);
void* fn_98_62B8(void*, short);
}

extern "C" void* fn_98_6248(char* object, short deleting) {
    if (object) {
        fn_27_1A1E70(object + 0x1c, short(-1));
        fn_98_62B8(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A1E70(void*, short);
void* fn_98_5AC8(void*, short);
}

extern "C" void* fn_98_5A50(char* object, short deleting) {
    if (object) {
        fn_27_1A1E70(object + 0x4b8, short(-1));
        if (object) fn_98_5AC8(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

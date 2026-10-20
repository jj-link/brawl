#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A1B88(void* member, short deleteFlag);
void* fn_98_5B40(void* object, short deleting);
}

extern "C" void* fn_98_5AC8(void* object, short deleting) {
    if (object) {
        fn_27_1A1B88(static_cast<char*>(object) + 0x48c, static_cast<short>(-1));
        if (object) fn_98_5B40(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

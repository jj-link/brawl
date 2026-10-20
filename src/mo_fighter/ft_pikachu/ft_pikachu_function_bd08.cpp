#include <new>
#pragma force_active on

extern "C" void* fn_98_BCA8(void*, short);
extern "C" void* fn_98_BB70(void*, short);

extern "C" void* fn_98_BD08(char* object, short deleting) {
    if (object) {
        fn_98_BCA8(object + 0xec, short(-1));
        if (object) fn_98_BB70(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

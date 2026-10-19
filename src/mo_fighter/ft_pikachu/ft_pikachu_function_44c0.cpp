#include <new>
#pragma force_active on

extern "C" {
void* fn_98_1E98(void*, short);
void* fn_98_1EF4(void*, short);

void* fn_98_44C0(char* object, short deleting) {
    if (object) {
        fn_98_1E98(object + 0x14, short(0));
        fn_98_1EF4(object + 8, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}

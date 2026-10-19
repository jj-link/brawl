#include <new>
#pragma force_active on

extern "C" {
void* fn_98_4F74(void*, short);
void* fn_98_53F8(void*, short);
}

extern "C" void* fn_98_4F04(char* object, short deleting) {
    if (object) {
        fn_98_4F74(object + 0x5f6c, short(-1));
        fn_98_53F8(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

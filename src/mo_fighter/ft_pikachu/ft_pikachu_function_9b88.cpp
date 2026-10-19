#include <new>
#pragma force_active on

extern "C" {
void* fn_27_C74E8(void*, short);
void* fn_98_18FC(char*, short);
}

extern "C" void* fn_98_9B88(char* object, short deleting) {
    if (object) {
        fn_27_C74E8(object + 0x2AE34, short(-1));
        fn_98_18FC(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

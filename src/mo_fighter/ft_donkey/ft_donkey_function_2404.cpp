#include <stddef.h>
#pragma force_active on

void operator delete(void*);

extern "C" {
void* fn_92_2204(void* object, short shouldDelete);
void* fn_92_22A0(void* ptr, short size);
void* fn_92_22E0(void* object, short flag);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_92_2404(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short d = -1;
        fn_92_2204(p + 0xDC, d);
        fn_92_22A0(p + 0xC0, d);
        fn_92_22E0(p + 0x14, d);
        if (object != 0) {
            fn_27_C7770(object, d);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#include <types.h>
#pragma force_active on

void operator delete(void*);

extern "C" {
void fn_27_614C4(void*, short);
void fn_27_D3080(void*, short);
}

extern "C" void* fn_111_5364(unsigned char* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_614C4(object + 0xAC, memberDeleting);
        if (object != 0) {
            fn_27_D3080(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

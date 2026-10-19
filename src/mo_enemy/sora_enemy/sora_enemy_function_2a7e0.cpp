#include <types.h>
#pragma force_active on

extern "C" void* fn_41_FBAC(void* p, short flag);
extern "C" void fn_27_69684(void* p, short flag);

extern "C" void* fn_41_2A7E0(void* p, short flag) {
    if (p != nullptr) {
        fn_41_FBAC((char*)p + 0x38, 0);
        fn_27_69684(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

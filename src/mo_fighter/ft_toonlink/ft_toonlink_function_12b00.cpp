#include <types.h>
#pragma force_active on

extern "C" {
void* fn_121_12AC0(void* p, short size);
}

extern "C" void* fn_121_12B00(void* p, short size) {
    if (p != nullptr) {
        fn_121_12AC0(p, 0);
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}

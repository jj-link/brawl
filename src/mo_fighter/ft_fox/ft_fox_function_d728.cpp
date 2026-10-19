#include <cstddef>
#pragma force_active on

extern "C" {
void fn_97_D6B0(void*, short);
void __dl__FPv(void*);

void* fn_97_D728(void* object, short deleting) {
    if (object != 0) {
        fn_97_D6B0(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}

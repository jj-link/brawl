#include <stddef.h>
#pragma force_active on

extern "C" void fn_94_14124(void* p, short x);
void operator delete(void* p);

extern "C" void* fn_94_140C8(void* p, short flag) {
    if (p != NULL) {
        fn_94_14124(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

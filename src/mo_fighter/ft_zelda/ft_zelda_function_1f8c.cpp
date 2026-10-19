#include <stddef.h>
#pragma force_active on

extern "C" void fn_27_1362C(void*, short);

extern "C" void* fn_104_1F8C(void* p, short flags) {
    if (p != NULL) {
        fn_27_1362C(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}

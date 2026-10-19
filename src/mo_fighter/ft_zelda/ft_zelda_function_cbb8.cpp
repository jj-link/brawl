#include <stddef.h>
#pragma force_active on

extern "C" void* fn_104_38A0(void*, short);

extern "C" void* fn_104_CBB8(void* p, short del) {
    if (p != NULL) {
        fn_104_38A0(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

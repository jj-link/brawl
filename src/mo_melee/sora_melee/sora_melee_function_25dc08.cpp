#include <types.h>
#pragma force_active on

extern "C" void* fn_27_25CEB8(void* p, int size);
void operator delete(void* p);

extern "C" void* fn_27_25DC08(void* p, int size) {
    if (p) {
        fn_27_25CEB8(p, 0);
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}

#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" {
void fn_63_2C40(void* self, int flag);

void* fn_63_15D4C(void* p, int n) {
    if (p) {
        fn_63_2C40(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}

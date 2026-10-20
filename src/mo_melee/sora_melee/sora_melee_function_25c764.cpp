#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_241EA4(void* a1, int a2);

void* fn_27_25C764(void* p, int del) {
    if (p) {
        fn_27_241EA4(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}
}

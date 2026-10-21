#include <types.h>
#pragma force_active on

struct S {
    unsigned : 4;
    unsigned f : 4;
    unsigned : 24;
};

extern "C" void fn_27_19F3C0(void* arg0, u32 arg1) {
    S* p = (S*)((char*)arg0 + 8);
    p->f = arg1;
}

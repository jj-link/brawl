#include <types.h>
#pragma force_active on

extern "C" void fn_54_6964(void* self, unsigned arg) {
    typedef struct { unsigned low : 4; unsigned high : 28; } T;
    T* p = (T*)self + 2;
    p->low = arg;
}

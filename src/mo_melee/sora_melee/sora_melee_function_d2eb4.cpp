#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D2D34(void* p, int n);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);

struct fn_27_D2EB4_Obj {
    u8 m_header[0xC];
    u8 m_elems[2][8];
};

extern "C" void* fn_27_D2EB4(fn_27_D2EB4_Obj* p, int n) {
    if (p) {
        __destroy_arr(p->m_elems, (void (*)(void*, int))fn_27_D2D34, 8, 2);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_46700(void*, int);
}

class Holder {
public:
    virtual ~Holder();
    u32 pad[2];
};

extern "C" void* fn_27_19D830(Holder* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_46700, 0x60, 12);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

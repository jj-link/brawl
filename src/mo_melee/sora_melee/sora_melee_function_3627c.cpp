#include <types.h>
#pragma force_active on

extern "C" {

void* fn_8015C1B0(void*, void*);

class Iface {
public:
    virtual void m0();
    virtual void* m1();
};

void fn_27_3627C(void* p1) {
    Iface* obj = *(Iface**)((char*)p1 + 8);
    void* b = obj->m1();
    void* list = (void**)((char*)b + 0x1c);
    void* node = 0;
    while (node = fn_8015C1B0(list, node)) {
        *(u8*)((char*)node + 0x24) = 0;
    }
}

}

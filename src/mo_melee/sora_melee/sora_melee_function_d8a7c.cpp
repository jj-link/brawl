#include <types.h>
#pragma force_active on

struct Interface {
    virtual void unused0();
    virtual void* get(void* p);
};

extern "C" void* fn_27_D8A7C(Interface* a0, u32* a1, void* a2) {
    void* result = a0->get(a2);
    *static_cast<u32*>(result) = *a1;
    return result;
}

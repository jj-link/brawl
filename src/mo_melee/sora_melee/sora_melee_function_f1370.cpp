#include <types.h>
#pragma force_active on

struct Interface {
    virtual void a();
    virtual void* call(void*);
};

extern "C" void* fn_27_F1370(Interface* obj, u32* out, void* arg) {
    void* p = obj->call(arg);
    *(u32*)p = *out;
    return p;
}

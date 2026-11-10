#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(s8* p, s32 n);
};

struct Wrapper {
    char pad[8];
    Object_vptr_0* object;
};

extern "C" {
void* fn_80280A28(Wrapper* arg0, s8 arg1) {
    s8 value = arg1;
    Object_vptr_0* obj = arg0->object;
    obj->slot3(&value, 1);
    return arg0;
}
}

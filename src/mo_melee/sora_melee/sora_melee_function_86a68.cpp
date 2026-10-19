#include <types.h>
#pragma force_active on

struct soTestObject {
    u32 vfunc0();
    virtual u32 func1();
    virtual u32 func2();
    virtual u32 func3();
    virtual u32 func4();
};

extern "C" {
u32 fn_27_86A68(soTestObject* object);
}

u32 fn_27_86A68(soTestObject* object) {
    return !object->func4();
}

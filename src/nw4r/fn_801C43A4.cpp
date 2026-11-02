#include "types.h"
#pragma force_active on

extern "C" void fn_801C32C4(void* self, int a, int b, int c, int d);

class Class_80466A60 {
public:
    virtual void fn_801C49AC();  // offset 0x8
    virtual void fn_801C46C4();  // offset 0xc
    virtual void fn_801BCBFC();  // offset 0x10
    virtual void fn_801BC66C();  // offset 0x14
    virtual void fn_801BC684();  // offset 0x18
    virtual void fn_801BC854();  // offset 0x1c
    virtual void fn_801BCAD8();  // offset 0x20
    virtual void fn_801BCAF0();  // offset 0x24
    virtual void fn_801C45E8();  // offset 0x28
    virtual void fn_801C49A4();  // offset 0x2c
    virtual void fn_801BCBF4();  // offset 0x30
    virtual void fn_801BD33C();  // offset 0x34
    virtual void fn_801BD368();  // offset 0x38
    virtual void fn_801BD40C();  // offset 0x3c
    virtual void fn_801BD414();  // offset 0x40
    virtual void fn_801BD41C();  // offset 0x44
    virtual void fn_801BD424();  // offset 0x48
    virtual void fn_801C4748();  // offset 0x4c
    virtual void fn_801BD4F4();  // offset 0x50
    virtual void fn_801BD548();  // offset 0x54
    virtual void fn_801BD584();  // offset 0x58
    virtual void fn_801C4830();  // offset 0x5c
    virtual void fn_801C4844();  // offset 0x60
    virtual void fn_801C4370();  // offset 0x64
};

extern "C" void fn_801C43A4(Class_80466A60* self, int a, int b, int c, int d) {
    self->fn_801C4370();
    fn_801C32C4((char*)self + 0xD8, a, b, c, d);
}

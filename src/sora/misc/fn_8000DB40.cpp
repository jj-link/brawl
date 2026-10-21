#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void f0();
    virtual void f1(u32 a, u32 b, u32 c);
};

struct Element {
    Obj* obj;
    u8 pad[0x14];
};

struct Owner {
    u8 padding[0x390];
    Element elements[1];
};

extern "C" void fn_8000DB40(Owner* self, u32 index) {
    self->elements[index].obj->f1(8, 0, 0);
}

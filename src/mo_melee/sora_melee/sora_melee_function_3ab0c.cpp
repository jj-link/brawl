#include <types.h>
#pragma force_active on

class Base {
public:
    virtual ~Base();
    virtual u32* f3();
};

struct Owner {
    u8 pad[0x30];
    Base* a;
    Base* b;
};

extern "C" {
    u32 fn_27_3AB0C(Owner* self, u32, u32 mode) {
        if (mode == 1) {
            return self->b->f3()[8];
        }
        return self->a->f3()[9];
    }
}

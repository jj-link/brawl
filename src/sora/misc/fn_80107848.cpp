#include <types.h>
#pragma force_active on

struct Data {
    u32 a, b, c, d, e;
};

struct Obj {
    u8 pad[0x6C];
    void* object;
};

extern "C" void fn_801092E0(void*, Data*);

extern "C" void fn_80107848(Obj* self, const Data* src) {
    if (self->object != 0) {
        Data local = *src;
        fn_801092E0(self->object, &local);
    }
}

#include <types.h>
#pragma force_active on

extern "C" {

void fn_27_138458(void* a, void* b, void* c, void* d, void* e);

struct Entry {
    void* a;
    void* b;
};

struct Obj {
    char pad0[0x0A];
    u8 index;
    char pad1[3];
    u8 flag;
    u8 type;
    char pad2[0x24];
    Entry arr[2];
};

void fn_27_116B7C(Obj* self, void* a, void* b, void* c, void* d) {
    if (self->type == 6) {
        fn_27_138458(self->arr[self->index].a, a, b, c, d);
        if (self->flag & 2) {
            fn_27_138458(self->arr[1].a, a, b, c, d);
        }
    }
}

}

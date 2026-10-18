#include <types.h>
#pragma force_active on

struct Buf {
    u32 a;
    u32 b;
    u32 c;
};

struct Obj {
    u8 pad[0x28];
    void* m28;
    void* m2c;
};

extern "C" {
void fn_800955B4(void* a, void* b, Buf* c);

void fn_27_1239C(Obj* self, void* p, Buf* src) {
    if (self->m28 != 0) {
        Buf tmp = *src;
        fn_800955B4(self->m28, p, &tmp);
    } else {
        void** q = (void**)self->m2c;
        if (q != 0) {
            Buf tmp = *src;
            fn_800955B4(*q, p, &tmp);
        }
    }
}
}

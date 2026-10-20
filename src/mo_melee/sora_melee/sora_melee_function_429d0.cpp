#include <types.h>
#pragma force_active on

struct This {
    u32 f0;
    s16 a; // +4
    s16 b; // +6
};

class Obj {
public:
    virtual void m0();
    virtual void* m1(int);
};

extern "C" void fn_27_417E4(void*, void*);

extern "C" void fn_27_429D0(This* self, Obj* obj, void* p) {
    for (int i = 0; i < self->b; i++) {
        void* r = obj->m1(self->a + i);
        fn_27_417E4(r, p);
    }
}

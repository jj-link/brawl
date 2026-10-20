#include <types.h>
#pragma force_active on

extern "C" void fn_27_B485C(void* p);
extern "C" void fn_27_B1720(void* p);

struct CamObj {
    virtual void* f0();
    virtual void* get(u32 i);
    virtual void* f2();
    virtual u32 getNum();
};

struct Self {
    char pad[0x18];
    CamObj* m;
};

extern "C" void fn_27_B242C(Self* self) {
    fn_27_B485C(self);
    s32 n = self->m->getNum();
    for (s32 i = 0; i < n; i++) {
        void* p = self->m->get(i);
        fn_27_B1720(p);
    }
}

#include <types.h>
#pragma force_active on

struct Inner { u8 pad[4]; u32 m4; };
struct Mid { u8 pad[0xD8]; Inner* mD8; };
class Class_3FE0 {
public:
    virtual void fn_27_4742C();
    virtual void* fn_27_4746C(u32);
};
struct Self {
    u8 pad0[0x2C];
    Mid* m2C;
    u32 m30;
    u8 pad34[4];
    u8 body[0x20];
    Class_3FE0* m58;
    u8 pad5C[0xA];
    u16 flag0 : 1;
    u16 flag1 : 1;
    u16 rest : 14;
};
extern "C" u32 fn_27_4238C(void*, void*, u32, u32, u32, float, float, float);
extern "C" void fn_27_36A8C(void*);
extern "C" void fn_27_43C04(Self* self, u32 a, u32 b, float f1, float f2, float f3) {
    if ((int)self->flag1 != 1) {
        u32 val = self->m2C->mD8->m4;
        void* result = self->m58->fn_27_4746C(b);
        if (fn_27_4238C(result, &self->body, self->m30, val, a, f1, f2, f3) == 1U && !self->flag0) {
            fn_27_36A8C(&self->body);
            self->flag0 = 1;
        }
    }
}
#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_107_rodata_C;
extern "C" const float lbl_107_rodata_28;

#pragma dont_inline on
extern "C" Vec2f* fn_107_EF04(Vec2f* dst, const Vec2f* src);
#pragma dont_inline reset

struct GWState {
    u8 pad0[0x8];
    Vec2f a;
    Vec2f b;
    Vec2f c;
    Vec2f d;
    Vec2f e;
    u8 pad1[0x30 - 0x30];
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" void fn_107_EF18(GWState* self) {
    Vec2f zero(lbl_107_rodata_C, lbl_107_rodata_C);
    Vec2f* p = fn_107_EF04(&self->d, &zero);
    p = fn_107_EF04(&self->b, p);
    p = fn_107_EF04(&self->a, p);
    Vec2f init(lbl_107_rodata_28, lbl_107_rodata_28);
    p = fn_107_EF04(&self->e, &init);
    fn_107_EF04(&self->c, p);
    self->flag31 = 0;
    self->flag30 = 0;
    self->flag32 = 1;
}

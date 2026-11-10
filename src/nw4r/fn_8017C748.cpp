#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on
struct Particle;
struct Emitter {
    char pad0[0x24];
    char* resource;
    char pad28[0x28];
    u16 count;
};
struct DrawContext {
    Emitter* emitter;
    char pad4[0xd0];
    int value;
};
struct Vertex {
    nw4r::math::VEC3 a, b, c;
    float t;
};
typedef Particle* (*FirstFn)(Emitter*);
typedef Particle* (*NextFn)(Emitter*, Particle*);
typedef void (*PositionFn)();
class Class_804654B0 {
public:
    virtual void fn_80174618();
    virtual void fn_80176480();
    virtual FirstFn fn_80176004(int);
    virtual NextFn fn_80176028(int);
    virtual PositionFn fn_80177D40(Emitter*);
};
extern "C" {
extern const float lbl_805A3038;
extern const float lbl_805A303C;
extern const double lbl_805A3040;
void fn_8017BC38(Class_804654B0*, Vertex*, DrawContext*, int, Particle*, PositionFn, float, float, float);
void fn_8017C0F0(Class_804654B0*, Vertex*, Vertex*, int, u8, int);
}
extern "C" void fn_8017C748(Class_804654B0* self, DrawContext* context, int flags) {
    char* resource;
    Particle* link;
    Emitter* emitter = context->emitter;
    resource = emitter->resource;
    PositionFn position = self->fn_80177D40(emitter);
    int reverse = *(u16*)(resource + 0x9c) & 0x800;
    FirstFn first = self->fn_80176004(reverse);
    NextFn next = self->fn_80176028(reverse);
    float x = lbl_805A3038 * (s8)resource[0x139];
    float y = lbl_805A3038 * (s8)resource[0x13a];
    int count = emitter->count;
    float step;
    switch (resource[0x142] & 0xc0) {
    case 0:
    default:
        step = lbl_805A303C / (float)count;
        break;
    case 0x40:
        step = lbl_805A303C;
        break;
    }
    int index = 0;
    int increment = 1;
    if (reverse != 0) {
        index = count;
        increment = -1;
    }
    Particle* particle = first(emitter);
    Vertex current;
    Vertex previous;
    Vertex initial;
    fn_8017BC38(self, &initial, context, flags, particle, position, x, y, step * (float)index);
    index = index + (increment);
    current = initial;
    link = next(emitter, particle);
    while (link) {
        previous = current;
        fn_8017BC38(self, &current, context, flags, link, position, x, y, step * (float)index);
        fn_8017C0F0(self, &previous, &current, flags, resource[0x140], context->value);
        link = next(emitter, link);
        index += increment;
    }
    initial.t = step * (float)index;
    fn_8017C0F0(self, &current, &initial, flags, resource[0x140], context->value);
}

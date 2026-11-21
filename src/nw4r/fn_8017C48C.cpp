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
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual FirstFn slot2(int);
    virtual NextFn slot3(int);
    virtual PositionFn slot4(Emitter*);
};
extern "C" {
extern const float lbl_805A3038;
extern const float lbl_805A303C;
void fn_8017BC38(Object_vptr_0*, Vertex*, DrawContext*, int, Particle*, PositionFn, float, float, float);
void fn_8017C0F0(Object_vptr_0*, Vertex*, Vertex*, int, u8, int);
}
extern "C" void fn_8017C48C(Object_vptr_0* self, DrawContext* context, int flags) {
    char* resource;
    Particle* link;
    Emitter* emitter = context->emitter;
    resource = emitter->resource;
    PositionFn position = self->slot4(emitter);
    int reverse = *(u16*)(resource + 0x9c) & 0x800;
    FirstFn first = self->slot2(reverse);
    NextFn next = self->slot3(reverse);
    float x = lbl_805A3038 * (s8)resource[0x139];
    float y = lbl_805A3038 * (s8)resource[0x13a];
    int count = emitter->count;
    float step;
    switch (resource[0x142] & 0xc0) {
    case 0:
    default:
        step = lbl_805A303C / (float)(count - 1);
        break;
    case 0x40:
        step = lbl_805A303C;
        break;
    }
    int index = 0;
    int increment = 1;
    if (reverse != 0) {
        index = count - 1;
        increment = -1;
    }
    Particle* particle = first(emitter);
    Vertex current;
    Vertex previous;
    fn_8017BC38(self, &current, context, flags, particle, position, x, y, step * (float)index);
    index = index + increment;
    link = next(emitter, particle);
    while (link) {
        previous = current;
        fn_8017BC38(self, &current, context, flags, link, position, x, y, step * (float)index);
        fn_8017C0F0(self, &previous, &current, flags, resource[0x140], context->value);
        link = next(emitter, link);
        index += increment;
    }
}

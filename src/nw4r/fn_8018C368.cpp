#include <types.h>
#pragma force_active on
#pragma optimize_for_size on
struct Vec2 { float x; float y; };
struct Item { Vec2 a; Vec2 b; Vec2 c; Vec2 d; };
struct Object { u8 pad; u8 count; Item* data; };
extern "C" void fn_8018C368(Object* self, const Item* src, u8 count) {
    self->count = self->count < count ? count : self->count;
    for (int i = 0; i < count; i++) {
        Vec2* p = &self->data[i].a;
        p->x = src->a.x; p->y = src->a.y;
        p = &self->data[i].b;
        p->x = src->b.x; p->y = src->b.y;
        p = &self->data[i].c;
        p->x = src->c.x; p->y = src->c.y;
        p = &self->data[i].d;
        p->x = src->d.x; p->y = src->d.y;
        ++src;
    }
}

#include <gr/collision/gr_collision.h>
#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

struct Ray { Vec2f pos; Vec2f dir; };
struct Words { u32 a, b, c, d; };
struct Result {
    char pad[0x14];
    float fraction;
    char pad18[8];
    Vec2f point;
    u8 hit;
    Ray ray;
};
extern float lbl_805A2A80;
extern "C" void fn_80040518(const Ray*, Result*);
extern "C" void fn_801380BC(Result*, u8*);

extern "C" u8 fn_80138348(Result* self, const Ray* ray) {
    self->hit = 0;
    *(Words*)&self->ray = *(const Words*)ray;
    self->fraction = 1.0f;
    fn_80040518(ray, self);
    nw4r::ut::LinkList<u8, 48>& list = *(nw4r::ut::LinkList<u8, 48>*)&g_grCollisionList;
    nw4r::ut::LinkList<u8, 48>::Iterator it = list.GetBeginIter();
    for (; it != list.GetEndIter(); ++it) {
        u8* obj = &*it;
        u8 flags = obj[0x2c];
        if ((flags >> 7 & 1) && (flags & 1) && (flags >> 2 & 1))
            fn_801380BC(self, obj);
    }
    if (self->hit == 1)
        self->point = ray->dir * self->fraction + ray->pos;
    return self->hit;
}
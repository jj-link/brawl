#include <nw4r/math/math_types.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, u32);
extern const float lbl_63_rodata_1C0;

static inline nw4r::math::VEC3 scaled(const nw4r::math::VEC3& in, float k) {
    nw4r::math::VEC3 out;
    LocalScale((const Vec*)&in, (Vec*)&out, k);
    return out;
}

struct Data {
    u32 id;
    u32 pad;
    nw4r::math::VEC3 position;
    u8 gap[0xC];
    nw4r::math::VEC3 rotation;
};
struct Callback {
    u32 pad;
    Data* data;
    u32 pad8;
    u32 state;
};
struct Model {
    u8 pad[0x11C];
    Callback* callback;
    u16 pad120;
    u16 mask;
};
struct Holder {
    Model* model;
};
struct Self {
    u8 pad0[0x44];
    Holder* holder;
    u8 pad48[0x7C];
    u32 id;
    u8 padc8[8];
    Callback cb;
    u8 pade0[0x88];
    Vec rot;
    u8 pad174[4];
    nw4r::math::VEC3* positions;
    u8* indexPtr;
};

extern "C" void fn_63_13FA0(Self* self) {
    Callback* p = &self->cb;
    if (p != 0) {
        Model* m = self->holder->model;
        if (m != 0) {
            if (m->callback == 0) {
                p->state = 0;
                p->data->id = self->id;
                m->callback = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                m->mask = (u16)p->data->id;
            }
            if (self->positions != 0) {
                u8 index = *self->indexPtr;
                if (index != 0xFF) {
                    Data* q = p->data;
                    const nw4r::math::VEC3& pos = self->positions[index];
                    q->position.x = pos.x;
                    q->position.y = pos.y;
                    q->position.z = pos.z;
                }
            }
            p->data->rotation = scaled(*(const nw4r::math::VEC3*)&self->rot, lbl_63_rodata_1C0);
        }
    }
}

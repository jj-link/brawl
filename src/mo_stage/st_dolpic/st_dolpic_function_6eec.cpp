#pragma force_active on
#include <types.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
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

struct Data {
    u32 id;
    char pad[0x4C];
    nw4r::math::MTX34 matrix;
};

struct Callback {
    u32 a;
    Data* data;
    u32 b;
    u32 c;
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdlSimple** models;
    char pad48[0x7C];
    u32 id;
    char padc8[8];
    Callback callback;
    char pade0[0x78];
    nw4r::math::VEC3 vec;
    nw4r::math::MTX34* matrix;
};

extern const float lbl_46_rodata_158;
extern "C" void fn_8003E828(nw4r::math::MTX34* a, const nw4r::math::VEC3* b, nw4r::math::MTX34* out);

static inline nw4r::math::VEC3 ScaleVector(const nw4r::math::VEC3& input, float factor) {
    nw4r::math::VEC3 output;
    LocalScale((const Vec*)&input, (Vec*)&output, factor);
    return output;
}

extern "C" void fn_46_6EEC(Object* self) {
    Callback* cb = &self->callback;
    if (cb) {
        nw4r::g3d::ScnMdlSimple* model = self->models[0];
        if (model) {
            if (!model->m_calcWorldCallBack) {
                cb->c = 0;
                cb->data->id = self->id;
                model->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)cb;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = cb->data->id;
            }
            nw4r::math::MTX34 m;
            nw4r::math::VEC3 v;
            m = *self->matrix;
            v = ScaleVector(self->vec, lbl_46_rodata_158);
            fn_8003E828(&m, &v, &m);
            cb->data->matrix = m;
        }
    }
}

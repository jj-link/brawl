#include <types.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <mt/mt_matrix.h>
#pragma force_active on

struct Data {
    u32 id;
    char pad[0x4C];
    Matrix matrix;
};
struct Callback {
    void* vtable;
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
    char pade0[0x84];
    Matrix* matrix;
    char pad168[0x38];
    float angle;
};
extern const float lbl_52_rodata_230;
extern const float lbl_52_rodata_214;
extern "C" void fn_8003E828(Matrix*, const Vec3f*, Matrix*);

static inline float multiply(float a, float b) { return b * a; }

extern "C" void fn_52_D638(Object* self) {
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
            if (self->matrix) {
                Vec3f scale;
                scale.m_z = lbl_52_rodata_230;
                scale.m_y = lbl_52_rodata_230;
                scale.m_x = lbl_52_rodata_230;
                Matrix m(self->matrix);
                m.rotY(multiply(self->angle, lbl_52_rodata_214));
                fn_8003E828(&m, &scale, &m);
                cb->data->matrix = m;
            }
        }
    }
}
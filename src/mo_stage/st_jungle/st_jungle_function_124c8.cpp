#pragma force_active on
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <snd/snd_3d_generator.h>
#include <mt/mt_vector.h>

struct Matrix { unsigned int v[12]; };
struct Data { unsigned int id; char pad[0x4c]; Matrix matrix; };
struct Callback { void* vtable; Data* data; unsigned int b; unsigned int c; };
struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdlSimple** models;
    char pad48[0x7c];
    unsigned int id;
    char padc8[8];
    Callback callback;
    char pade0[0x78];
    Matrix* matrix;
    char pad15c[0x14];
    float x, y, z;
    char pad17c[0x14];
    char sound[4];
};
extern "C" void fn_8003F074(Matrix*, float, float, float);
extern const float lbl_51_rodata_1E0;
extern const float lbl_51_rodata_1E4;

extern "C" void fn_51_124C8(Object* self) {
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
            Matrix* src = self->matrix;
            if (src) {
                Matrix m = *src;
                Vec3f offset(lbl_51_rodata_1E0, lbl_51_rodata_1E4, lbl_51_rodata_1E0);
                fn_8003F074(&m, offset.m_x, offset.m_y, offset.m_z);
                fn_8003F074(&m, self->x, self->y, self->z);
                cb->data->matrix = m;
            }
            Data* data = cb->data;
            float z = *(float*)&data->matrix.v[11];
            float y = *(float*)&data->matrix.v[7];
            float x = *(float*)&data->matrix.v[3];
            Vec3f pos;
            pos.m_x = x;
            pos.m_y = y;
            pos.m_z = z;
            ((snd3DGenerator*)self->sound)->setPos(&pos);
        }
    }
}
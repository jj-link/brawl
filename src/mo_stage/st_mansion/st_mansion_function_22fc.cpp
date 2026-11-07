#include <gr/gr_gimmick.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <nw4r/math/math_arithmetic.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

struct Data {
    unsigned int id;
    char pad[4];
    Vec3f pos;
    char pad14[12];
    Vec3f scale;
    Vec3f rotation;
};
struct Callback {
    void* vtable;
    Data* data;
    unsigned int b;
    unsigned int c;
};
struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdlSimple** models;
    char pad48[0x78];
    unsigned int index;
    unsigned int id;
    char padc8[8];
    Callback callback;
    char pade0[0x8c];
    float* ratio;
    char pad170[4];
    Vec3f rotation;
    float scale;
    unsigned char state;
    char pad185[0x23];
    snd3DGenerator sound;
};
extern "C" const float lbl_47_rodata_70;
extern "C" const float lbl_47_rodata_74;
inline float clamp(float x, float low, float high) {
    float v = nw4r::math::FSelect(x - low, x, low);
    return nw4r::math::FSelect(v - high, high, v);
}
extern "C" void fn_47_22FC(Object* self) {
    Callback* cb = &self->callback;
    if (cb) {
        nw4r::g3d::ScnMdlSimple* model = self->models[self->index];
        if (model) {
            cb->c = 0;
            cb->data->id = self->id;
            model->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)cb;
            model->EnableScnMdlCallbackTiming(1);
            model->m_nodeIndex = cb->data->id;
        }
        cb->data->pos = ((grGimmick*)self)->getPos();
        cb->data->rotation = self->rotation;
        float scale;
        float ratio;
        if (self->state == 1)
            ratio = lbl_47_rodata_70 - *self->ratio;
        else
            ratio = *self->ratio;
        scale = self->scale;
        Data* data = cb->data;
        data->scale.m_x = scale;
        data->scale.m_y = scale * clamp(ratio, lbl_47_rodata_74, lbl_47_rodata_70);
        data->scale.m_z = scale;
        Vec3f pos;
        pos = ((grGimmick*)self)->getPos();
        self->sound.setPos(&pos);
    }
}
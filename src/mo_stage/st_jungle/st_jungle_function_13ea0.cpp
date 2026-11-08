#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

struct CallbackData {
    unsigned int id;
    unsigned int unknown;
    Vec3f position;
    char pad[0x18];
    Vec3f rotation;
};
struct Callback : nw4r::g3d::ICalcWorldCallBack {
    CallbackData* data;
    unsigned int unknown;
    unsigned int state;
};
struct Object {
    char pad0[0x44];
    nw4r::g3d::ScnMdlSimple** models;
    char pad48[0x7c];
    unsigned int id;
    char padc8[8];
    Callback callback;
    char pade0[0x78];
    Vec3f* position;
    char pad15c[0x14];
    Vec3f rotation;
    char pad17c[0x18];
    snd3DGenerator generator;
};

extern "C" void fn_51_13EA0(Object* self) {
    Callback* callback = &self->callback;
    if (callback) {
        nw4r::g3d::ScnMdlSimple* model = *self->models;
        if (model) {
            if (!model->m_calcWorldCallBack) {
                callback->state = 0;
                callback->data->id = self->id;
                model->m_calcWorldCallBack = callback;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = callback->data->id;
            }
            Vec3f* position = self->position;
            if (position) {
                callback->data->position = *position;
                callback->data->rotation = self->rotation;
            }
            self->generator.setPos(self->position);
        }
    }
}
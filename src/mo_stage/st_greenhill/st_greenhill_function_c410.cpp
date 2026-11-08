#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

struct MatHolder {
    u32 unk;
    Matrix m;
};

struct CallbackData {
    u32 id;
    char pad[0x4C];
    Matrix matrix;
};

struct Callback {
    void* vtable;
    CallbackData* data;
    u32 b;
    u32 c;
};

struct Model {
    char pad[0x11C];
    Callback* callback;
    u16 a;
    u16 id;
};

struct Object {
    char pad44[0x44];
    Model** models;
    char pad48[0x7C];
    u32 id;
    char padc8[8];
    Callback callback;
    char pade0[0x78];
    MatHolder* matrix;
    snd3DGenerator sound;
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(Model*, u32);
extern const float lbl_72_rodata_E4;

extern "C" void fn_72_C410(Object* self) {
    Callback* cb = &self->callback;
    if (cb) {
        Model* model = self->models[0];
        if (model) {
            if (!model->callback) {
                cb->c = 0;
                cb->data->id = self->id;
                model->callback = cb;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                model->id = cb->data->id;
            }
            float z = *(float*)((char*)self->matrix + 0x30);
            float y = *(float*)((char*)self->matrix + 0x20);
            float x = *(float*)((char*)self->matrix + 0x10);
            Vec3f pos;
            pos.m_x = x;
            pos.m_y = y;
            pos.m_z = z;
            Vec3f rot;
            self->matrix->m.getRotate(&rot);
            Matrix m;
            m = self->matrix->m;
            Matrix r;
            m.rotY(lbl_72_rodata_E4);
            m.mul(&r, &m);
            cb->data->matrix = m;
            self->sound.setPos(&pos);
        }
    }
}

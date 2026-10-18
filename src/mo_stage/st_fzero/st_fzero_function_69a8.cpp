#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Matrix {
    u32 v[12];
};

struct Data {
    u32 id;
    u8 pad[0x4C];
    Matrix matrix;
};

struct Callback {
    u32 a;
    Data* data;
    u32 b;
    u32 c;
};

struct Model {
    u8 pad[0x11C];
    Callback* callback;
    u16 a;
    u16 id;
};

struct Object {
    u8 pad[0x44];
    Model** models;
    u8 pad48[0x7C];
    u32 id;
    u8 padc8[8];
    Callback callback;
    u8 pade0[0x7C];
    u8 state;
    u8 pad15d[11];
    Matrix* matrix;
    float x, y, z;
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(Model*, u32);
extern "C" void setIdentity__6MatrixFv(Matrix*);
extern "C" void fn_8003F074(Matrix*, float, float, float);

extern "C" void fn_61_69A8(Object* self) {
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

            Matrix m;
            if (self->state == 7)
                setIdentity__6MatrixFv(&m);
            else
                m = *self->matrix;

            fn_8003F074(&m, self->x, self->y, self->z);
            cb->data->matrix = m;
        }
    }
}

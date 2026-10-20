#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Matrix {
    u32 v[12];
};

struct CallbackData {
    u32 id;
    char pad[0x4C];
    Matrix matrix;
};

struct Callback {
    void* vtable;
    CallbackData* data;
    u32 unknown;
    u32 state;
};

struct Model {
    char pad[0x11C];
    Callback* callback;
    u16 unknown;
    u16 id;
};

struct Object {
    char pad0[0x44];
    Model** model;
    char pad1[0x7C];
    u32 id;
    char pad2[8];
    Callback callback;
    char pad3[0x7C];
    Matrix* matrix;
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(
    void* model, unsigned long flag);

extern "C" void fn_61_5F28(Object* self) {
    Callback* callback = &self->callback;
    if (callback) {
        Model* model = *self->model;
        if (model) {
            if (!model->callback) {
                callback->state = 0;
                callback->data->id = self->id;
                model->callback = callback;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                model->id = callback->data->id;
            }
            if (self->matrix) {
                callback->data->matrix = *self->matrix;
            }
        }
    }
}

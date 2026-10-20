#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Matrix {
    u32 words[12];
};

struct CallbackData {
    u32 id;
    char pad04[0x4c];
    Matrix matrix;
};

struct Callback {
    u32 unknown00;
    CallbackData* data;
    u32 unknown08;
    u32 flag;
};

struct Model {
    char pad00[0x11c];
    Callback* callback;
    u16 unknown120;
    u16 callbackId;
};

struct ModelHolder {
    Model* model;
};

struct Object {
    char pad00[0x44];
    ModelHolder* holder;
    char pad48[0x7c];
    u32 id;
    char padC8[8];
    Callback callback;
    char padE0[0x80];
    Matrix* matrix;
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(
    void*, unsigned long);

extern "C" void fn_57_8F20(Object* self) {
    Callback* callback = &self->callback;
    if (callback) {
        Model* model = self->holder->model;
        if (model) {
            if (!model->callback) {
                callback->flag = 0;
                callback->data->id = self->id;
                model->callback = callback;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                model->callbackId = callback->data->id;
            }
            if (self->matrix) {
                callback->data->matrix = *self->matrix;
            }
        }
    }
}

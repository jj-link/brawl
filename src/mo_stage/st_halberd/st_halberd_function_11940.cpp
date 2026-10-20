#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Matrix {
    float m[3][4];
};

struct Vec3f {
    float x, y, z;
};

struct CallbackData {
    u32 id;
    char pad04[0x4c];
    Matrix matrix;
};

struct Callback {
    void* vtable;
    CallbackData* data;
    u32 unk08;
    u32 unk0c;
};

struct Model {
    char pad00[0x11c];
    Callback* callback;
    u16 unk120;
    u16 callbackId;
};

struct Motion {
    char pad00[0x60];
    Matrix matrix60;
    Matrix matrix90;
};

struct Object {
    char pad00[0x44];
    Model** models;
    char pad48[0x88];
    Callback callback;
    char padE0[0x7c];
    unsigned char* mode;
    Motion* motion;
    char pad164[0x8c];
    char sound[4];
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(Model*, u32);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);

extern "C" void fn_57_11940(Object* self) {
    Callback* cb = &self->callback;
    if (!cb)
        return;

    Model* model = self->models[0];
    if (!model)
        return;

    if (!model->callback) {
        cb->unk0c = 0;
        model->callback = cb;
        EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
        model->callbackId = cb->data->id;
    }

    Motion* motion = self->motion;
    if (!motion)
        return;

    Matrix matrix;
    switch (*self->mode) {
    case 1:
        matrix = motion->matrix60;
        break;
    case 0:
        matrix = motion->matrix90;
        break;
    default:
        return;
    }

    cb->data->matrix = matrix;

    float z = matrix.m[2][3];
    float y = matrix.m[1][3];
    float x = matrix.m[0][3];
    Vec3f pos;
    pos.y = y;
    pos.x = x;
    pos.z = z;
    setPos__14snd3DGeneratorFP5Vec3f(self->sound, &pos);
}

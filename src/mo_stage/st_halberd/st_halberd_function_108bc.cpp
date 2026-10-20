#pragma force_active on
typedef unsigned int u32;

struct Matrix {
    float a[12];
};

struct Vec3f {
    float x, y, z;
};

struct Data {
    u32 id;
    char pad[0x4c];
    Matrix matrix;
};

struct Callback {
    void* vtable;
    Data* data;
    u32 unk;
    u32 state;
};

struct Model {
    char pad[0x11c];
    Callback* callback;
    unsigned short unk;
    unsigned short id;
};

struct Obj {
    char pad0[0x44];
    Model** models;
    char pad1[0x7c];
    u32 id;
    char pad2[8];
    Callback callback;
    char pad3[0x80];
    Matrix* matrix;
    char pad4[0x18];
    char generator[1];
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(
    void*, unsigned long);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);

extern "C" void fn_57_108BC(Obj* self) {
    Callback* cb = &self->callback;
    if (cb) {
        Model* model = self->models[0];
        if (model) {
            if (!model->callback) {
                cb->state = 0;
                cb->data->id = self->id;
                model->callback = cb;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(
                    model, 1);
                model->id = cb->data->id;
            }
            if (self->matrix) {
                Matrix n;
                Matrix m = *self->matrix;
                n = m;
                cb->data->matrix = m;
                Vec3f pos;
                pos.x = n.a[3];
                pos.y = n.a[7];
                pos.z = n.a[11];
                setPos__14snd3DGeneratorFP5Vec3f(self->generator, &pos);
            }
        }
    }
}

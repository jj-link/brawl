#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Matrix {
    u32 v[12];
};

struct Vec3f {
    float x, y, z;
};

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

struct Model {
    char pad[0x11C];
    Callback* callback;
    u16 a;
    u16 id;
};

struct Object {
    char pad[0x44];
    Model** models;
    char pad48[0x7C];
    u32 id;
    char padc8[8];
    Callback callback;
    char pade0[0x80];
    Matrix* matrix;
    char pad164[8];
    float x, y, z;
    char pad178[0x18];
    char sound[4];
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(Model*, u32);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);
extern "C" void fn_8003F074(Matrix*, float, float, float);

extern "C" void fn_62_931C(Object* self) {
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
            Matrix* src = self->matrix;
            if (src) {
                Matrix m = *src;
                fn_8003F074(&m, self->x, self->y, self->z);
                cb->data->matrix = m;
                float z = *(float*)&m.v[11];
                float y = *(float*)&m.v[7];
                float x = *(float*)&m.v[3];
                Vec3f pos;
                pos.y = y;
                pos.x = x;
                pos.z = z;
                setPos__14snd3DGeneratorFP5Vec3f(self->sound, &pos);
            }
        }
    }
}

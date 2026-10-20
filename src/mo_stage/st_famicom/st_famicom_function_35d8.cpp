#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Vec3f {
    float x, y, z;
};

struct CallbackData {
    u32 id;
    u32 unknown;
    Vec3f position;
};

struct Callback {
    void* vtable;
    CallbackData* data;
    u32 unknown;
    u32 state;
};

struct Model {
    char pad[0x11c];
    Callback* callback;
    u16 unknown;
    u16 id;
};

struct Object {
    char pad0[0x44];
    Model** models;
    char pad48[0x7c];
    u32 id;
    char padc8[8];
    Callback callback;
    char pade0[0x78];
    Vec3f* position;
    char pad15c[0x88];
    char generator[4];
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(Model*, u32);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);

extern "C" void fn_68_35D8(Object* self) {
    Callback* callback = &self->callback;
    if (callback) {
        Model* model = *self->models;
        if (model) {
            if (!model->callback) {
                callback->state = 0;
                callback->data->id = self->id;
                model->callback = callback;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                model->id = callback->data->id;
            }

            Vec3f* position = self->position;
            if (position) {
                callback->data->position = *position;
            }

            setPos__14snd3DGeneratorFP5Vec3f(self->generator, self->position);
        }
    }
}

#pragma force_active on
typedef unsigned long u32;
typedef unsigned short u16;

struct Model;

struct Handler {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void attach(Model*);
    virtual void set(int, void*);
};

struct Data {
    u32 flags;
    u32 unused;
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Callback {
    u32 unused;
    Data* data;
    u32 pad;
    u32 state;
};

struct Model {
    char pad0[0xD4];
    Handler* handler;
    char pad1[0x44];
    Callback* callback;
    u16 pad2;
    u16 flags;
};

struct ModelRef {
    Model* model;
};

struct Vec2 {
    float x, y;
};

struct Object {
    char pad0[0x44];
    ModelRef* ref;
    char pad1[0x88];
    Callback callback;
    char pad2[0x78];
    Vec2* position;
    u32 value0;
    u32 value1;
    Handler handler;
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, u32);
extern const float lbl_74_rodata_1C0;

extern "C" void fn_74_D230(Object* self) {
    Callback* callback = &self->callback;
    if (callback) {
        Model* model = self->ref->model;
        if (model) {
            if (!model->callback) {
                callback->state = 0;
                model->callback = callback;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                model->flags = callback->data->flags;
                self->handler.attach(model);
                model->handler = &self->handler;
            }
            if (self->position) {
                callback->data->set(self->position->x, self->position->y, lbl_74_rodata_1C0);
                self->handler.set(0, &self->value0);
                self->handler.set(1, &self->value1);
            }
        }
    }
}

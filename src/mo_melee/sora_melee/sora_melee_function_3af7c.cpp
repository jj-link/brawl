#pragma force_active on

struct Vec3 {
    float x, y, z;
};

struct Data {
    char pad0[0x40];
    int value;
    Vec3 position;
    char pad50[8];
    int enabled;
    short kind;
    unsigned char flags;
    unsigned char index;
    void* handle;
    unsigned char state;
};

struct Provider {
    virtual void v0();
    virtual Data* get(int);
};

struct ProviderNoArg {
    virtual void v0();
    virtual Data* get();
};

struct Object {
    char pad0[0x34];
    Provider* provider;
    char pad38[0x30];
    char target[4];
};

extern "C" void fn_27_37A64(void*, void*, void*);

extern "C" void fn_27_3AF7C(
    Object* self,
    int index,
    const Vec3* position,
    int value,
    int kind,
    int flags
) {
    if (((ProviderNoArg*)self->provider)->get()->state == 1) {
        Data* data = self->provider->get(index);
        data->value = value;
        data->enabled = 1;
        data->kind = kind;
        data->flags = flags;
        data->index = index;
        data->position = *position;
        fn_27_37A64(
            self->target,
            self->provider->get(index)->handle,
            &self->provider->get(index)->value
        );
    }
}

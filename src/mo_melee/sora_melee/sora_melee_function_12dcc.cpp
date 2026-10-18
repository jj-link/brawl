#pragma force_active on
typedef float f32;

struct Vec3 {
    f32 x, y, z;
};

struct Base {
    virtual void f0();
    virtual void* get();
};

struct Holder {
    unsigned char pad[0x30];
    int enabled;
    Base* object;
};

struct Object {
    unsigned char pad[0x10];
    Vec3 position;
};

extern "C" void fn_27_12DCC(Holder* self, void*, Vec3* position) {
    if (self->enabled) {
        Object* object = (Object*)self->object->get();
        float x = position->x;
        float y = position->y;
        object->position.x = x;
        float z = position->z;
        object->position.y = y;
        object->position.z = z;
    }
}

#pragma force_active on
struct FlagObject {
    unsigned char pad[0x2c];
    unsigned char flags;
};

struct Object {
    unsigned char pad[0x2c];
    void* active;
    FlagObject* object;
};

extern "C" bool fn_27_25FC4(Object* self) {
    if (!self->active || !self->object) {
        return false;
    }
    return (self->object->flags >> 7) & 1;
}

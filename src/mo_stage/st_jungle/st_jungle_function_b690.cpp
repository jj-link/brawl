#pragma force_active on

typedef unsigned int u32;

struct Vec3f {
    float x, y, z;
};

struct snd3DGenerator;

struct CallbackData {
    char pad00[0x80];
    u32 objectId;
    u32 flags;
    char pad88[0x18];
    Vec3f position;
};

struct Callback {
    void* vtable;
    CallbackData* data;
    void* owner;
    u32 state;
};

struct ObjectBase {
    char pad00[0x3C];
};

#define SLOT(n) virtual void slot##n();

struct Object : ObjectBase {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    virtual void getPosition(Vec3f*, int, u32);

    char pad40[0xD0 - 0x40];
    Callback callback;
    char padE0[0x198 - 0xE0];
    Vec3f position;
    float scaleY;
    u32 objectId;
    char pad1AC[4];
    char generator[4];
};

#undef SLOT

extern "C" void fn_51_3E64(Object*);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);

extern "C" void fn_51_B690(Object* self) {
    fn_51_3E64(self);

    Callback* callback = &self->callback;
    if (callback) {
        callback->data->flags |= 4;
        callback->data->objectId = self->objectId;
        callback->data->position = self->position;
        callback->data->position.y *= self->scaleY;

        Vec3f position;
        self->getPosition(&position, 0, self->objectId);
        setPos__14snd3DGeneratorFP5Vec3f(
            (snd3DGenerator*)self->generator, &position);
    }
}

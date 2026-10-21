#pragma force_active on
typedef unsigned int u32;

struct Vec3f {
    float x, y, z;
};

struct snd3DGenerator;

struct CallbackData {
    u32 id;
    u32 flags;
    char pad08[0x2C - 8];
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

struct Object : ObjectBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void getPosition(Vec3f*, int, u32);

    char pad40[0xD0 - 0x40];
    Callback callback;
    char padE0[0x194 - 0xE0];
    Vec3f position;
    char generator[4];
};

extern "C" void fn_51_3E64(Object*);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);

extern "C" void fn_51_11E74(Object* self) {
    fn_51_3E64(self);

    Callback* callback = &self->callback;
    if (callback) {
        callback->data->flags |= 0x10;
        callback->data->position = self->position;

        Vec3f position;
        self->getPosition(&position, 0, callback->data->id);
        setPos__14snd3DGeneratorFP5Vec3f(
            (snd3DGenerator*)self->generator, &position);
    }
}

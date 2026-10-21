#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct ObjectBase {
    char padding[0x3C];
};

#define VIRTUAL_SLOTS_8(n) \
    virtual void slot##n##_0(); \
    virtual void slot##n##_1(); \
    virtual void slot##n##_2(); \
    virtual void slot##n##_3(); \
    virtual void slot##n##_4(); \
    virtual void slot##n##_5(); \
    virtual void slot##n##_6(); \
    virtual void slot##n##_7();

struct Object : ObjectBase {
    VIRTUAL_SLOTS_8(0)
    VIRTUAL_SLOTS_8(1)
    VIRTUAL_SLOTS_8(2)
    VIRTUAL_SLOTS_8(3)
    VIRTUAL_SLOTS_8(4)
    VIRTUAL_SLOTS_8(5)
    virtual void getPos(Vec3f*, int, unsigned int);
    VIRTUAL_SLOTS_8(6)
    VIRTUAL_SLOTS_8(7)
    VIRTUAL_SLOTS_8(8)
    VIRTUAL_SLOTS_8(9)
    VIRTUAL_SLOTS_8(10)
    VIRTUAL_SLOTS_8(11)
    VIRTUAL_SLOTS_8(12)
    VIRTUAL_SLOTS_8(13)
    virtual void slot113();
    virtual void slot114();
    virtual void update();

    char padding40[0xC4 - 0x40];
    unsigned int node;
    char paddingC8[0x14C - 0xC8];
    int ready;
    char padding150[0x178 - 0x150];
    unsigned char state;
    char padding179[7];
    char generator[1];
};

#undef VIRTUAL_SLOTS_8

extern "C" void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);

extern "C" void fn_68_11B1C(Object* self) {
    if (self->state == 1) {
        Vec3f pos;
        self->getPos(&pos, 0, self->node);
        setPos__9grGimmickFP5Vec3f(self, &pos);
        setPos__14snd3DGeneratorFP5Vec3f(self->generator, &pos);
    } else {
        self->update();
        if (self->ready != 0)
            self->state = 1;
    }
}

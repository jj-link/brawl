#pragma force_active on
class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void update();
};

struct Context {
    Object* objects[5];
    unsigned char padding[16];
    unsigned char unused : 2;
    unsigned char disabled : 1;
    unsigned char remaining : 5;
};

extern "C" void fn_27_1FF0C(Context* self) {
    if (!self->disabled) {
        if (self->objects[0]) self->objects[0]->update();
        if (self->objects[1]) self->objects[1]->update();
        if (self->objects[2]) self->objects[2]->update();
        if (self->objects[3]) self->objects[3]->update();
        if (self->objects[4]) self->objects[4]->update();
    }
}

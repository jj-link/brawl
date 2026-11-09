#pragma force_active on

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setFrame(float);
};

struct Context {
    Object* objects[5];
    float field14;
    unsigned char pad18[4];
    float field1C;
    unsigned char pad20[4];
    unsigned char unused : 2;
    unsigned char disabled : 1;
    unsigned char remaining : 5;
};

extern "C" void fn_27_2058C(Context* self) {
    float frame = self->field1C;
    if (!self->disabled) {
        if (self->objects[0]) self->objects[0]->setFrame(frame);
        if (self->objects[1]) self->objects[1]->setFrame(frame);
        if (self->objects[2]) self->objects[2]->setFrame(frame);
        if (self->objects[3]) self->objects[3]->setFrame(frame);
        if (self->objects[4]) self->objects[4]->setFrame(frame);
        self->field14 = frame;
    }
}

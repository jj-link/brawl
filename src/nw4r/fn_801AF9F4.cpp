#pragma force_active on
class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct State {
    char padding[0x124];
    Target* objects[5];
};

extern "C" void fn_801AF9F4(State* self) {
    if (self->objects[0]) self->objects[0]->v7();
    if (self->objects[1]) self->objects[1]->v7();
    if (self->objects[2]) self->objects[2]->v7();
    if (self->objects[3]) self->objects[3]->v7();
    if (self->objects[4]) self->objects[4]->v7();
}

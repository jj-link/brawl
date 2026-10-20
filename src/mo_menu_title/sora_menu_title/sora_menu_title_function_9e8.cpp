#pragma force_active on
struct Object {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void call(unsigned int, unsigned int);

    char pad[0xE0];
    unsigned int value;
};

struct Parent {
    char pad[0x48];
    Object* object;
};

struct Arguments {
    char pad[0xC];
    unsigned int value;
};

struct Context {
    char pad[0x44];
    Parent* parent;
    Arguments* args;
};

extern "C" void fn_24_9E8(Context* self) {
    Object* object = self->parent->object;
    object->call(object->value, self->args->value);
}

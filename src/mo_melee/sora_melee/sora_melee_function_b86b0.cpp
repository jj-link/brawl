#pragma force_active on
struct Receiver {
    char pad[8];
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void method(unsigned int, void*, unsigned int);
};

struct Object {
    char pad[0x44];
    unsigned int arg;
    Receiver* receiver;
    char data[0x1c];
    unsigned int last;
};

extern "C" void fn_27_B86B0(Object* self) {
    self->receiver->method(self->arg, self->data, self->last);
}

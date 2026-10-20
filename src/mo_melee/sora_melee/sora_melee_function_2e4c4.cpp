#pragma force_active on
struct Object;

struct Dispatch {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void call(void*, Object*, int);
};

struct Data {
    char pad[0xC];
    void* value;
};

struct Module {
    char pad[0xD8];
    Data* data;
};

struct Object {
    char pad0[0x44];
    Dispatch* dispatch;
    char pad1[0xC];
    Module* module;
};

extern "C" void fn_27_2E4C4(Object* self, int value) {
    self->dispatch->call(self->module->data->value, self, value);
}

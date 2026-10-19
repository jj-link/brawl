#pragma force_active on
struct Interface {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void call(void*) = 0;
};

struct Object {
    unsigned char pad[0x68];
    void* arg;
    unsigned long pad2;
    Interface* object;
};

extern "C" void fn_6_A344(Object* self) {
    self->object->call(self->arg);
}

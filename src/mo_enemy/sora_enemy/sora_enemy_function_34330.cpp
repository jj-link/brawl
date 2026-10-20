#pragma force_active on
class emSubObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class emOwner {
public:
    char pad[0x10];
    emSubObj sub;
};

extern "C" {
void fn_41_34330(emOwner* self) {
    self->sub.f1();
}
}

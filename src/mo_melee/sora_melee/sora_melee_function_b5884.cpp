#pragma force_active on
class B5884Object {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void invoke();
};

class B5884SecondObject {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void invoke(void*);
};

struct B5884Context {
    unsigned char pad[0x24];
    B5884Object* first;
    unsigned char pad2[0x04];
    B5884SecondObject* second;
};

extern "C" void fn_27_B5884(B5884Context* self, void* arg) {
    self->first->invoke();
    self->second->invoke(arg);
}

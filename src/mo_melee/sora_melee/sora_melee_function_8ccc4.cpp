#pragma force_active on
struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int get(unsigned long);
};

struct C {
    char pad[0x64];
    V* value;
};

struct B {
    char pad[0xD8];
    C* value;
};

struct A {
    char pad[0x60];
    B* value;
};

extern "C" int getWorkInt__23soExternalValueAccesserFP11StageObjectUl(
    void* object, unsigned long index) {
    return reinterpret_cast<A*>(object)->value->value->value->get(index);
}

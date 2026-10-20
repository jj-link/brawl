#include <types.h>
#pragma force_active on

class EntityA {
public:
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
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21(int, void*);
};

class EntityB {
public:
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
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void* f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void* f38();
};

struct Manager {
    void* _0x0;
    void* _0x4;
    EntityB* entity_b;
    char pad[0x70];
    EntityA* entity_a;
};

struct Outer {
    char pad[0xd8];
    Manager* manager;
};

extern "C" void* fn_114_10BB8(void* a, Outer* arg) {
    EntityB* b = arg->manager->entity_b;
    void* result = b->f38();
    if (result != 0) {
        arg->manager->entity_a->f21(0x13, arg);
        result = b->f34();
    }
    return result;
}

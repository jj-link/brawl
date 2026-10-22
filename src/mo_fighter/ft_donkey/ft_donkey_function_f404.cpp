#pragma force_active on

struct Param {
    int id;
    float a;
    float b;
    char p0, p1, p2, p3;
};

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
    virtual int f16();
    virtual void f17();
    virtual void f18();
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
    virtual void f30(Param*);
    virtual void f31();
};

struct Manager {
    void* _0;
    void* _4;
    EntityB* entity_b;
    char pad[0x70 - 0xc];
    EntityA* entity_a;
};

struct Outer {
    char pad[0xd8];
    Manager* manager;
};

extern "C" void fn_27_194B34(void*);
extern const float lbl_92_rodata_60;
extern const float lbl_92_rodata_64;

extern "C" void fn_92_F404(void* self, Outer* arg) {
    Outer* a = arg;
    switch (a->manager->entity_a->f16()) {
    case 0x97:
        Param param;
        param.id = 0xFB;
        param.a = lbl_92_rodata_60;
        param.b = lbl_92_rodata_64;
        param.p0 = 0;
        param.p1 = 0;
        param.p2 = 0;
        param.p3 = 0;
        a->manager->entity_b->f30(&param);
        EntityB* eb = a->manager->entity_b;
        fn_27_194B34(a);
        eb->f7();
        break;
    }
}

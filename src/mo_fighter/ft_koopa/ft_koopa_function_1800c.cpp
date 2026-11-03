#pragma force_active on

struct KoopaData {
    int first;
    unsigned char flag;
    unsigned char padding[3];
    int second;
    int value0;
    int value1;
    int value2;
    float scalar;
    unsigned char last;
};

class ModuleA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual unsigned int check(int);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void send(int, KoopaData*, int);
    virtual void v17();
    virtual void v18();
    virtual int get(int);
};

class ModuleB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(int, unsigned int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void onFlag(unsigned int);
};

struct Modules {
    char pad0[0x54];
    ModuleA* a;
    char pad1[0x64 - 0x58];
    ModuleB* b;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_102_E384(KoopaData*, int, int, unsigned char);
extern "C" void fn_102_17444(Accesser*);

extern "C" void fn_102_1800C(void*, Accesser* accesser) {
    fn_102_17444(accesser);
    if (accesser->modules->a->check(0) == 1U) {
        KoopaData data;
        fn_102_E384(&data, 0x26, 0x1BA, 1);
        accesser->modules->a->send(0, &data, 0);
        ModuleB* b = accesser->modules->b;
        b->set(accesser->modules->a->get(0), 0x20000002);
        accesser->modules->b->set(data.value0, 0x20000003);
        accesser->modules->b->set(data.value1, 0x20000004);
    }
    accesser->modules->b->onFlag(0x22000010);
}

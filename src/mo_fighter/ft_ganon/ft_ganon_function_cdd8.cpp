#pragma force_active on

extern "C" void fn_109_CA24(void*, int, int, int);

struct Event {
    int type;
    unsigned char flag;
    int a;
    int b;
    int c;
    int d;
    float value;
    unsigned char enabled;
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void send(int, Event*, int);
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
};

struct Modules {
    char pad[0x54];
    ModuleA* a;
    char pad58[0x64 - 0x58];
    ModuleB* b;
};

struct Fighter {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_109_CDD8(void*, Fighter* fighter) {
    Event event;
    fn_109_CA24(&event, 0x21, 0x1b4, 1);
    fighter->modules->a->send(0, &event, 0);
    ModuleB* b = fighter->modules->b;
    b->set(fighter->modules->a->get(0), 0x20000002);
    fighter->modules->b->set(event.b, 0x20000003);
    fighter->modules->b->set(event.c, 0x20000004);
}

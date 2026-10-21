#pragma force_active on

extern "C" const float lbl_109_rodata_10;

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

class LinkModule {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void send(int, Event*, int);
    virtual void v17(); virtual void v18();
    virtual int get(int);
};

class WorkModule {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void set(int, unsigned int);
};

struct Modules {
    char pad[0x54];
    LinkModule* link;
    char pad58[0xc];
    WorkModule* work;
};

struct Fighter {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_109_C46C(void*, Fighter* fighter) {
    Event event;
    event.type = 11;
    event.flag = 0;
    event.a = -1;
    event.b = -1;
    event.c = -1;
    event.d = -1;
    event.value = lbl_109_rodata_10;
    event.enabled = 1;

    fighter->modules->link->send(0, &event, 0);
    WorkModule* work = fighter->modules->work;
    work->set(fighter->modules->link->get(0), 0x20000002);
    fighter->modules->work->set(event.b, 0x20000003);
    fighter->modules->work->set(event.c, 0x20000004);
}

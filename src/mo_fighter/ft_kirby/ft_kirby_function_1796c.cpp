#pragma force_active on
struct LinkEvent {
    int kind;
    bool flag;

    LinkEvent() : kind(0x13), flag(false) {}
};

struct LinkModule {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual bool isLinked(int);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void sendEventNodes(int, LinkEvent&, unsigned int);
};

struct CatchModule {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void call(int, bool);
};

struct HitModule {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void call(int);
};

struct Modules {
    char pad0[0x20];
    HitModule* hit;
    char pad24[0x18];
    CatchModule* catcher;
    char pad40[0x14];
    LinkModule* link;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_96_1796C(void*, Accesser* accesser, int status) {
    switch (status) {
    case 0x11B:
    case 0x121:
        if (accesser->modules->link->isLinked(0) == true) {
            LinkEvent event;
            accesser->modules->link->sendEventNodes(0, event, 0);
        }
        break;
    case 0x11A:
        return;
    default:
        if (accesser->modules->link->isLinked(0) == true) {
            accesser->modules->catcher->call(0, true);
        }
        accesser->modules->hit->call(0);
        break;
    }
}

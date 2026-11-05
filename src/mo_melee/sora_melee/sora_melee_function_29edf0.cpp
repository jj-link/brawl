#pragma force_active on

struct SubObject;
struct Modules;

struct Work {
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
    virtual void call(int);
};

struct Motion {
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
    virtual void call(int);
};

struct Other {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void call(int, SubObject*);
};

struct Modules {
    char pad0[0x64];
    Work* work;
    char pad1[8];
    Other* other;
    char pad2[0x1C];
    Motion* motion;
};

struct SubObject {
    char pad[0xD8];
    Modules* modules;
};

struct Item {
    char pad[0x60];
    SubObject* sub;
};

extern "C" void setVanishMode__8BaseItemFb(void*, bool);

extern "C" void fn_27_29EDF0(void*, Item* item, int flag) {
    Work* work = item->sub->modules->work;

    switch (flag) {
    case 0:
        setVanishMode__8BaseItemFb(item, false);
        work->call(0x12000008);
        item->sub->modules->motion->call(0);
        item->sub->modules->other->call(5, item->sub);
        break;
    default:
        return;
    }
}

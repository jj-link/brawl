#pragma force_active on
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
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};

struct Modules {
    char padding[0x64];
    Work* work;
};

struct Object {
    char padding[0xD8];
    Modules* modules;
};

extern "C" void fn_27_3A34B8(void*, Object* object) {
    object->modules->work->onFlag(0x22000011);
    object->modules->work->offFlag(0x22000012);
    object->modules->work->offFlag(0x22000013);
}

#pragma force_active on
struct Module {
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
    virtual void call(int);
};

struct Modules {
    unsigned char padding[0x40];
    Module* module;
};

struct Object {
    unsigned char padding[0xD8];
    Modules* modules;
};

extern "C" void fn_27_186F80(void*, Object* object) {
    object->modules->module->call(0);
}

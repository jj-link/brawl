#pragma force_active on

struct Work {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int getInt(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void increment(unsigned int);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void setInt(unsigned int, int);
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual bool isFlag(unsigned int);
    virtual void onFlag(unsigned int);
};

struct Modules {
    char padding[0x64];
    Work* work;
};

struct Object {
    char padding[0xD8];
    Modules* modules;
};

extern "C" void fn_27_16B950(void*, Object* object) {
    if (!object->modules->work->isFlag(0x22000011)) {
        if (object->modules->work->getInt(0x10000038) <= 0) {
            object->modules->work->onFlag(0x22000011);
        }
    }
    object->modules->work->increment(0x20000004);
    object->modules->work->setInt(0x20000006, 0);
    object->modules->work->setInt(0x20000007, 0);
}

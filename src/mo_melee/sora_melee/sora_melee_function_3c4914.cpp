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
    virtual int isFlag(unsigned int);
    virtual void unused();
    virtual void offFlag(unsigned int);
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
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void call(int);
};

struct Modules {
    char pad0[0x64];
    Work* work;
    char pad1[0x20];
    Motion* motion;
};

struct Object {
    char pad0[0xd8];
    Modules* modules;
};

extern "C" void fn_27_3C4914(void*, Object* object, int kind) {
    switch (kind) {
    case 0x119:
        return;
    }

    if (object->modules->work->isFlag(0x22000013)) {
        object->modules->motion->call(0x23);
        object->modules->work->offFlag(0x22000013);
    }
}

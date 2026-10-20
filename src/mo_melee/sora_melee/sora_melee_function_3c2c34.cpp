#pragma force_active on
struct Work {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual int isFlag(int);
    virtual void unused17();
    virtual void offFlag(int);
};

struct Status {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void change(int);
};

struct Modules {
    char pad[0x64];
    Work* work;
    char pad2[0x20];
    Status* status;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_3C2C34(void*, Object* object, int value) {
    switch (value) {
    case 0x11a:
        return;
    default:
        break;
    }

    if (object->modules->work->isFlag(0x22000013)) {
        object->modules->status->change(0x23);
        object->modules->work->offFlag(0x22000013);
    }
}

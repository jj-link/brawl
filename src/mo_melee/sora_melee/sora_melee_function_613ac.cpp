#pragma force_active on

class Work {
public:
    virtual void unused();
    virtual int* get();
};

class Module {
public:
    unsigned char padding[8];

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
    virtual Work* getWork();
};

struct Modules {
    unsigned char unused[0x38];
    Module* module;
};

struct Object {
    unsigned char unused[0xd8];
    Modules* modules;
};

extern "C" int fn_27_613AC(Object self, int value) {
    int* values = self.modules->module->getWork()->get();
    if (values) {
        for (int i = 0; i < 22; ++i) {
            if (value == values[i])
                return i;
        }
        return 0;
    }
    return 0;
}

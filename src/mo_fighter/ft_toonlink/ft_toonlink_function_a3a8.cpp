#pragma force_active on
struct StatusModule {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int getStatus();
};

struct Modules {
    unsigned char padding[0x70];
    StatusModule* status;
};

struct Fighter {
    unsigned char padding[0xD8];
    Modules* modules;
};

extern "C" void fn_121_FD14(void*, Fighter*);

extern "C" void fn_121_A3A8(void*, void* arg, Fighter* fighter) {
    if (fighter->modules->status->getStatus() == 0x116) {
        fn_121_FD14(arg, fighter);
    }
}

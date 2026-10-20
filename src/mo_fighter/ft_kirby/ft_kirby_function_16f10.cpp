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
    virtual int getStatusKind();
};

struct ModuleAccesser {
    unsigned char padding[0x70];
    StatusModule* statusModule;
};

struct Fighter {
    unsigned char padding[0xD8];
    ModuleAccesser* accesser;
};

extern "C" void fn_96_173B4(void*, Fighter*);

extern "C" void fn_96_16F10(void* self, Fighter* fighter) {
    switch (fighter->accesser->statusModule->getStatusKind()) {
    case 0x11B:
    case 0x11C:
        fn_96_173B4(self, fighter);
        break;
    }
}

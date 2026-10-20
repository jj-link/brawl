#pragma force_active on
struct Module {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void set(int, unsigned int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void clear(bool, bool);
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
    virtual void reset(int);
};

struct Modules {
    char pad00[0x3c];
    Module* motion;
    Module* posture;
    char pad44[0x20];
    Module* work;
};

struct Fighter {
    char pad00[0xd8];
    Modules* modules;
};

extern "C" void fn_92_FB1C(void*, Fighter* fighter, int status) {
    int value = -1;

    switch (status) {
    case 0x120:
    case 0x121:
    case 0x122:
    case 0x123:
    case 0x124:
    case 0x125:
    case 0x126:
    case 0x127:
    case 0x128:
    case 0x129:
        break;
    case 0x12a:
        value = 0x1e0;
        break;
    case 0x12b:
        value = 0x1e1;
        break;
    case 0x12c:
        value = 0x1e2;
        break;
    case 0x12d:
        value = 0x1e3;
        break;
    default:
        Module* motion = fighter->modules->motion;
        motion->clear(0, 0);
        Module* posture = fighter->modules->posture;
        posture->reset(0);
        break;
    }

    if (value != -1) {
        Module* work = fighter->modules->work;
        work->set(value, 0x20000000);
        Module* posture = fighter->modules->posture;
        posture->reset(0);
    }
}

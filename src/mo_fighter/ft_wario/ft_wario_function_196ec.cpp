#pragma force_active on
struct Vec3 {
    float x, y, z;
};

class WorkModule {
public:
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
    virtual float getFloat(int);
};

class VectorModule {
public:
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
    virtual void setVector(Vec3*, int);
};

struct ModuleAccesser {
    unsigned char padding0[0x0C];
    VectorModule* vectorModule;
    unsigned char padding1[0x54];
    WorkModule* workModule;

    WorkModule& getWorkModule() { return *workModule; }
    VectorModule& getVectorModule() { return *vectorModule; }
};

struct Fighter {
    unsigned char padding[0xD8];
    ModuleAccesser* modules;
};

extern "C" const float lbl_110_rodata_180;

extern "C" void fn_110_196EC(void*, Fighter* fighter) {
    ModuleAccesser* modules = fighter->modules;
    VectorModule* vectorModule;
    WorkModule* work = &modules->getWorkModule();
    Vec3 vector;
    vector.x = -work->getFloat(
        (vectorModule = modules->vectorModule, 0x21000000));
    vector.y = lbl_110_rodata_180;
    vector.z = lbl_110_rodata_180;
    vectorModule->setVector(&vector, 0);
}

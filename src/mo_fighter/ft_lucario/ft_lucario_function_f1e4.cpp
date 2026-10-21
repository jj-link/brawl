#pragma force_active on
#include <math.h>

extern const float lbl_118_rodata_30[];

struct WorkModule {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(unsigned long);
};

struct PostureModule {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void setLR(float);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void update();
};

struct Modules {
    char pad00[0xC];
    PostureModule* posture;
    char pad10[0x54];
    WorkModule* work;
};

struct Fighter {
    char pad00[0xD8];
    Modules* modules;
};

extern "C" float fn_118_F1E4(Fighter* fighter) {
    const float* constants = lbl_118_rodata_30;
    WorkModule* work = fighter->modules->work;
    float value = work->getFloat(0x21000008);
    float lr;

    if ((float)fabs(value) <= constants[9]) {
        lr = work->getFloat(0x21000004);
    } else if (value > constants[0]) {
        lr = constants[3];
    } else {
        lr = constants[2];
    }

    fighter->modules->posture->setLR(lr);
    fighter->modules->posture->update();
    return lr;
}

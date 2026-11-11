#pragma force_active on

extern "C" {
extern const unsigned char lbl_95_data_2C38[];
extern const unsigned char lbl_95_data_810C[];
extern const unsigned char lbl_95_data_81D8[];
extern const float lbl_95_rodata_E0;

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Vec2 {
    float x, y;
};

struct Modules;

struct Situation {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getKind(Modules*);
};

struct FloatSource {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float getFloat();
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setParam(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(int);
};

struct Kinetic {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Vec2 getSumSpeed(const short&);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void process(int, void*);
};

struct Modules {
    char pad0[0x0c];
    FloatSource* floatSource;
    char pad1[4];
    Situation* situation;
    char pad2[0x4c];
    Work* work;
    char pad3[0x14];
    Kinetic* kinetic;
    Situation* getSituation() { return situation; }
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_95_12D80(void*, Accesser* accesser) {
    Modules* modules = accesser->modules;
    Work* work = modules->work;
    Situation* situation = modules->getSituation();
    FloatSource* floatSource = modules->floatSource;
    Kinetic* kinetic = modules->kinetic;

    Vec2 speed;
    if (situation->getKind(modules) != 2) {
        float scalar = floatSource->getFloat();
        float value = work->getFloat(0x21000006);
        speed.x = value * scalar;
        speed.y = lbl_95_rodata_E0;
    } else {
        short mask = -1;
        Vec2 returned = kinetic->getSumSpeed(mask);
        speed.x = returned.x;
        speed.y = returned.y;
    }

    kinetic->process(0x65, accesser);
    void* ptr1 = __dynamic_cast(
        kinetic->getEnergy(2), 0, lbl_95_data_81D8, lbl_95_data_2C38, 1);
    void* ptr2 = __dynamic_cast(
        kinetic->getEnergy(1), 0, lbl_95_data_810C, lbl_95_data_2C38, 1);

    Vec2 out;
    out.x = speed.x;
    out.y = lbl_95_rodata_E0;
    *(float*)((char*)ptr1 + 8) = out.x;
    *(float*)((char*)ptr1 + 12) = out.y;
    *(float*)((char*)ptr2 + 12) = speed.y;

    work->setParam(-1, 0x20000008);
}

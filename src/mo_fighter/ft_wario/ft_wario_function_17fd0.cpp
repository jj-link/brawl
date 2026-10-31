#pragma force_active on

struct Vec2Words {
    unsigned int x;
    unsigned int y;
};

struct ParamView {
    char pad0[0x0C];
    float end;
    char pad1[0x20];
    float scale;
    float threshold;
};

struct WeaponView {
    char pad[0x2980];
    ParamView* param;
};

struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual int isFlag(unsigned long);
    virtual void clearFlag(unsigned long);
    virtual void setFlag(unsigned long);
};

struct Kinetic {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual Vec2Words getVector(short*);
};

struct Collision {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void clear(unsigned long);
    virtual void v6(); virtual void v7();
    virtual void setState(unsigned long, unsigned long);
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13();
    virtual int isActive(unsigned long, bool);
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
    virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void v47();
    virtual void setValue(float);
};

extern "C" {
extern const unsigned char lbl_110_data_5EF0[];
extern const unsigned char lbl_110_data_212C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_110_1526C(Vec2Words*);
}

extern "C" void fn_110_17FD0(void*, void* accesser_) {
    char* accesser = (char*)accesser_;
    char* enumeration = *(char**)(accesser + 0xD8);
    Work* work = *(Work**)(enumeration + 0x64);
    Kinetic* kinetic = *(Kinetic**)(enumeration + 0x7C);
    Collision* collision = *(Collision**)(enumeration + 0x1C);
    WeaponView* weapon = (WeaponView*)__dynamic_cast(
        *(void**)(accesser + 0x08), 0x3C,
        lbl_110_data_5EF0, lbl_110_data_212C, 1);
    ParamView* param = weapon->param;

    short input = 1;
    Vec2Words vector = kinetic->getVector(&input);
    float value = fn_110_1526C(&vector);
    float threshold = param->threshold;

    if (value <= threshold) {
        if (collision->isActive(0, false) != 0) {
            collision->clear(0);
            work->clearFlag(0x2200000A);
        }
    } else {
        float ratio = (value - threshold) / (param->end - threshold);
        float scaled = param->scale * ratio;

        if (collision->isActive(0, false) != 0) {
            collision->setValue(scaled);
        } else if (work->isFlag(0x2200000A) != 0) {
            collision->setState(0, 0);
            collision->setValue(scaled);
            work->setFlag(0x2200000A);
        }
    }
}

#pragma force_active on
extern "C" {
extern const unsigned char lbl_95_data_7A88[];
extern const unsigned char lbl_95_data_2C38[];
extern const float lbl_95_rodata_B0;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Situation {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getKind();
    virtual void v4();
    virtual int isChanged();
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void changeKinetic(int, void*);
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setFloat(float, int);
};

struct Energy {
    unsigned char pad[6];
    bool flag;
};

struct Modules {
    unsigned char pad0[0x14];
    Situation* situation;
    unsigned char pad1[0x4c];
    Work* work;
    unsigned char pad2[0x14];
    Kinetic* kinetic;
};

struct Accesser {
    unsigned char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_95_11FB0(void*, Accesser* accesser) {
    Modules* modules = accesser->modules;
    Work* work = modules->work;
    Situation* situation = modules->situation;
    Kinetic* kinetic = modules->kinetic;

    if (situation->isChanged()) {
        Energy* energy = static_cast<Energy*>(__dynamic_cast(
            kinetic->getEnergy(3), 0,
            lbl_95_data_7A88, lbl_95_data_2C38, 1));

        if (situation->getKind() == 0) {
            kinetic->changeKinetic(6, accesser);
            energy->flag = false;
        } else {
            kinetic->changeKinetic(10, accesser);
            energy->flag = true;
        }
    }

    if (situation->getKind() == 0) {
        work->setFloat(lbl_95_rodata_B0, 0x21000008);
    } else {
        work->setFloat(lbl_95_rodata_B0, 0x21000008);
        work->setInt(0, 0x20000006);
    }
}

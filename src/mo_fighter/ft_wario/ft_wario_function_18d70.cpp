#pragma force_active on

struct Vec3 {
    float x, y, z;
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float get(unsigned long);
    virtual void set(float, unsigned long);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void flag(unsigned long);
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void setRot(Vec3*, unsigned long);
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
};

extern "C" const float lbl_110_rodata_168;

extern "C" void fn_110_18D70(void*, unsigned char* obj, int event) {
    if (event == 2) {
        unsigned char* modules = *(unsigned char**)(obj + 0xD8);
        Work* work = *(Work**)(modules + 0x64);
        Posture* posture = *(Posture**)(modules + 0xC);

        float f0 = work->get(0x21000000);
        work->set(-f0, 0x21000000);

        float f1 = work->get(0x21000001);
        work->set(-f1, 0x21000001);

        float f2 = work->get(0x21000002);
        work->set(-f2, 0x21000002);

        float f3 = work->get(0x21000003);
        work->set(-f3, 0x21000003);

        posture->v11();
        posture->v19();

        Vec3 rot;
        rot.x = f0;
        rot.y = lbl_110_rodata_168;
        rot.z = lbl_110_rodata_168;
        posture->setRot(&rot, 0);

        work->flag(0x22000002);
        posture->v9();

        float dummy;
        work->set(dummy, 0x21000008);
    }
}

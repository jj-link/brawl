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

struct Motion {
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
    virtual void apply(const Vec3*, int);
};

extern "C" const float lbl_110_rodata_14C;

extern "C" void fn_110_185DC(void*, unsigned char* obj, int event) {
    if (event == 8) {
        unsigned char* modules = *(unsigned char**)(obj + 0xD8);
        Work* work = *(Work**)(modules + 0x64);
        Motion* motion = *(Motion**)(modules + 0xC);

        float x = work->get(0x21000000);
        work->set(-x, 0x21000000);

        float y = work->get(0x21000002);
        work->set(-y, 0x21000002);

        Vec3 v;
        v.x = x;
        v.y = lbl_110_rodata_14C;
        v.z = lbl_110_rodata_14C;
        motion->apply(&v, 0);

        work->flag(0x22000002);
    }
}

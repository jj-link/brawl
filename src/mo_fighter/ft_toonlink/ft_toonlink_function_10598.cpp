#pragma force_active on

struct Vec3f {
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
};

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float get();
};

extern "C" const float lbl_121_rodata_64;
extern "C" void fn_121_10510(Vec3f*, void*);
extern "C" void fn_121_F12C(Vec3f*, const Vec3f*);
extern "C" void fn_121_10470(Vec3f*, const Vec3f*, const Vec3f*);

extern "C" void fn_121_10598(void* arg0, void* arg1) {
    Vec3f vec;
    Vec3f sp20;
    Vec3f sp14;
    Vec3f sp8;

    unsigned char* a1 = (unsigned char*)arg1;
    unsigned char* modules = *(unsigned char**)(a1 + 0xD8);
    Work* work = *(Work**)(modules + 0x64);
    Inner* inner = *(Inner**)(modules + 0xC);

    float val = inner->get();
    float a = work->get(0x11000013);
    vec.x = a * val;
    vec.y = work->get(0x11000014);
    vec.z = lbl_121_rodata_64;

    fn_121_10510(&sp14, arg1);
    fn_121_F12C(&sp20, &sp14);
    fn_121_10470(&sp8, &sp20, &vec);
    fn_121_F12C((Vec3f*)arg0, &sp8);
}
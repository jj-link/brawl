#pragma force_active on
struct V4 {
    float x;
    float y;
    float z;
    float w;
};

struct Out {
    short a;
    short b;
    unsigned short c;
    unsigned short d;
    unsigned char e;
    unsigned char f;
    unsigned char g;
    unsigned char h;
};

struct Iface {
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void get2(V4* a, V4* b) = 0;
    virtual void s11() = 0;
    virtual void get1(V4* a) = 0;
    virtual int get0() = 0;
};

struct Frame {
    V4 v10;
    V4 v20;
    V4 v30;
    V4 v40;
    V4 v50;
    V4 v60;
    V4 v70;
} __attribute__((aligned(16)));

extern "C" void fn_802878F0(V4* out, int a, V4* in);
extern "C" void fn_80287A64(V4* out, int a, V4* in);

extern "C" void fn_8031CD64(Out* arg0, Iface* arg1, Iface* arg2, int arg3) {
    Frame f;

    arg1->get1(&f.v70);
    arg2->get1(&f.v60);
    fn_802878F0(&f.v50, arg3, &f.v60);

    f.v40.x = f.v50.x - f.v70.x;
    f.v40.y = f.v50.y - f.v70.y;
    f.v40.z = f.v50.z - f.v70.z;
    f.v40.w = f.v50.w - f.v70.w;

    arg1->get2(&f.v40, &f.v30);
    arg0->a = (short)*(int*)&f.v30.w;

    f.v40.x = f.v50.x - f.v30.x;
    f.v40.y = f.v50.y - f.v30.y;
    f.v40.z = f.v50.z - f.v30.z;
    f.v40.w = f.v50.w - f.v30.w;
    fn_80287A64(&f.v20, arg3, &f.v40);

    f.v20.x = -f.v20.x;
    f.v20.y = -f.v20.y;
    f.v20.z = -f.v20.z;
    f.v20.w = -f.v20.w;

    arg2->get2(&f.v20, &f.v10);
    arg0->b = (short)*(int*)&f.v10.w;
    arg0->c = 0xFFFF;
    arg0->d = 0xFFFF;
    arg0->e = 1;
    arg0->f = 1;
    arg0->g = (unsigned char)arg1->get0();
    arg0->h = (unsigned char)arg2->get0();
}
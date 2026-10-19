#pragma force_active on
typedef unsigned int u32;

struct Base {
    u32 a;
    u32 b;
};

struct Obj : Base {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void g(u32 x, u32 y);
    virtual void s23();
    virtual u32 f();
};

extern "C" u32 fn_109_9158(Obj* obj, u32 a, u32 b) {
    u32 result = obj->f();
    if (result == 1) {
        obj->g(a, b);
    }
    return result;
}

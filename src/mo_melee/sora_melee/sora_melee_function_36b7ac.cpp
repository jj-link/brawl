#pragma force_active on
typedef unsigned long u32;
typedef void (*WorkMethod)(void*);

extern "C" WorkMethod __vt__19soGeneralWorkSimple[];

struct WorkBase {
    WorkMethod* vptr0;
    bool nullable;
};

struct WorkInterface : WorkBase {
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void clearWorkAll();
};

struct Work : WorkInterface {
    void* data1;
    int count1;
    void* data2;
    int count2;
    void* data3;
    int count3;
};

inline void initialize(Work* w, void* p2, void* p3) {
    u32* fields = (u32*)w;
    fields[2] = (u32)__vt__19soGeneralWorkSimple;
    fields[0] = (u32)(__vt__19soGeneralWorkSimple + 2);
    fields[4] = 11;
    fields[5] = (u32)p2;
    fields[6] = 7;
    fields[7] = (u32)p3;
    fields[8] = 1;
    w->clearWorkAll();
}

extern "C" void* fn_27_36B7AC(char* p) {
    Work* w = (Work*)(p + 0x4c);
    w->nullable = false;
    w->data1 = p;
    initialize(w, p + 0x2c, p + 0x48);
    return p;
}

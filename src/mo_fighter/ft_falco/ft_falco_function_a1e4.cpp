#pragma force_active on
extern "C" void* fn_108_A290();
extern "C" void fn_27_3523D4(void*, void*, void*, void*, void*, void*, void*);

struct Base {
    int a;
    int b;
};

class Result {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void* m8();
    virtual void m9();
    virtual void* m10();
};

class MainObj : public Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual Result* m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
};

struct Wrapper {
    MainObj* obj;
};

struct Fighter {
    char pad[0xd8];
    Wrapper* wrapper;
};

extern "C" void fn_108_A1E4(void* arg0, Fighter* arg1) {
    MainObj* obj = arg1->wrapper->obj;
    void* r30 = (obj->m4())->m8();
    void* r31 = (obj->m4())->m10();
    fn_27_3523D4(fn_108_A290(), arg0, arg1, r31, r30, (void*)1, (void*)0);
}
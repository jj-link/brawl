#pragma force_active on
extern "C" void* fn_112_A0A4();
extern "C" void fn_27_35A480(void*, void*, void*, void*, void*, void*, void*);

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

struct Base {
    int a;
    int b;
};

class Object_vptr_0 : public Base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Result* slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
};

struct Wrapper {
    Object_vptr_0* obj;
};

struct Fighter {
    char pad[0xd8];
    Wrapper* wrapper;
};

extern "C" void fn_112_9FF8(void* arg0, Fighter* arg1) {
    Object_vptr_0* obj = arg1->wrapper->obj;
    void* r30 = (obj->slot4())->m8();
    void* r31 = (obj->slot4())->m10();
    fn_27_35A480(fn_112_A0A4(), arg0, arg1, r31, r30, (void*)1, (void*)0);
}

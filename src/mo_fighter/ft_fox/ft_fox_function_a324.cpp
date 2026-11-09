#pragma force_active on
extern "C" void* fn_97_A3D0();
extern "C" void fn_27_31E9D4(void*, void*, void*, void*, void*, void*, void*);

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
    virtual void* m8();  // offset 0x28
    virtual void m9();
    virtual void* m10();  // offset 0x30
};

struct Base {
    int a;
    int b;
};

class Object_vptr_0 : public Base {
public:
    virtual void fn_97_8138();  // offset 0x8
    virtual void slot1();  // offset 0xc
    virtual void slot2();  // offset 0x10
    virtual void slot3();  // offset 0x14
    virtual Result* slot4();  // offset 0x18
    virtual void slot5();  // offset 0x1c
    virtual void slot6();  // offset 0x20
    virtual void slot7();  // offset 0x24
    virtual void slot8();  // offset 0x28
    virtual void slot9();  // offset 0x2c
    virtual void slot10();  // offset 0x30
};

struct Wrapper {
    Object_vptr_0* obj;
};

struct Fighter {
    char pad[0xd8];
    Wrapper* wrapper;
};

extern "C" void fn_97_A324(void* arg0, Fighter* arg1) {
    Object_vptr_0* obj = arg1->wrapper->obj;
    void* r30 = (obj->slot4())->m8();
    void* r31 = (obj->slot4())->m10();
    fn_27_31E9D4(fn_97_A3D0(), arg0, arg1, r31, r30, (void*)1, (void*)0);
}

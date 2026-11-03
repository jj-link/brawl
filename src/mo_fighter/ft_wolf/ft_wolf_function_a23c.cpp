#pragma force_active on
extern "C" void* fn_125_A2E8();
extern "C" bool fn_27_3C8114(void* a0, void* p1, void* self,
                            void* p3, void* p4, void* p5, void* p6);

class Class_78E0 {
public:
    virtual void fn_125_8060();  // offset 0x8
    virtual void fn_125_1057C();  // offset 0xc
    virtual void fn_125_10A38();  // offset 0x10
    virtual void fn_125_10A34();  // offset 0x14
    virtual void fn_125_10A30();  // offset 0x18
    virtual void fn_125_10A2C();  // offset 0x1c
    virtual void fn_125_10A24();  // offset 0x20
    virtual void fn_125_10A6C();  // offset 0x24
    virtual void* fn_125_10A64();  // offset 0x28
    virtual void fn_125_10A5C();  // offset 0x2c
    virtual void* fn_125_10A54();  // offset 0x30
};

class Class_7A60 {
public:
    virtual void fn_125_8060();  // offset 0x8
    virtual void fn_125_10520();  // offset 0xc
    virtual void fn_125_10BFC();  // offset 0x10
    virtual void fn_125_10BF4();  // offset 0x14
    virtual void fn_125_10BEC();  // offset 0x18
    virtual void fn_125_10BE4();  // offset 0x1c
    virtual void fn_125_10BDC();  // offset 0x20
    virtual void fn_125_10BD4();  // offset 0x24
    virtual void fn_125_10BCC();  // offset 0x28
    virtual void fn_125_10BC4();  // offset 0x2c
    virtual void fn_125_10BBC();  // offset 0x30
};

struct Pad {
    int a;
    int b;
};

class Holder : public Pad {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Class_78E0* v4();
};

struct Accessor {
    Holder* holder;
};

struct Fighter {
    char pad[0xd8];
    Accessor* accessor;
};

extern "C" void fn_125_A23C(void* arg0, Fighter* arg1) {
    Holder* h = arg1->accessor->holder;
    void* r30 = h->v4()->fn_125_10A64();
    void* r31 = h->v4()->fn_125_10A54();
    fn_27_3C8114(fn_125_A2E8(), arg0, arg1, r31, r30, (void*)1, (void*)0);
}

#pragma force_active on

#define V(n) virtual void d##n();
#define V10(n) V(n##0) V(n##1) V(n##2) V(n##3) V(n##4) V(n##5) V(n##6) V(n##7) V(n##8) V(n##9)
#define V100(n) V10(n##0) V10(n##1) V10(n##2) V10(n##3) V10(n##4) V10(n##5) V10(n##6) V10(n##7) V10(n##8) V10(n##9)

struct Pad {
    char p[0x3c];
};

struct Fighter : Pad {
    V100(0)
    V10(10) V10(11) V10(12) V10(13) V10(14)
    V10(15) V10(16) V10(17)
    V(180) V(181) V(182) V(183) V(184)
    virtual void* getOwner();
};

struct ObjA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct Pad8 {
    char p[8];
};

struct ResultObj;

struct Mod0 : Pad8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual ResultObj* m4();
};

struct ResultObj {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual int w15();
};

#undef V
#undef V10
#undef V100

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(void*);
void fn_91_FE5C(void*, int, int, int, int);
extern const char lbl_91_data_2B20[];
extern const char lbl_91_data_33D4[];
}

extern "C" int fn_91_9DE4(void* self, char* accesser) {
    Fighter* fighter = (Fighter*)__dynamic_cast(
        *(void**)(accesser + 8), 0x3c,
        lbl_91_data_2B20, lbl_91_data_33D4, 1);
    char* modules = *(char**)(accesser + 0xd8);
    ObjA* objA = (ObjA*)(*(void**)(modules + 20));
    int valB;
    Mod0* mod = *(Mod0**)modules;
    const int taskId = *(int*)(*(char**)(accesser + 8) + 0x28);
    valB = objA->v3();
    void* owner = fighter->getOwner();
    int ownerId = fn_27_111364(owner);
    void* result = mod->m4();
    int valA = ((ResultObj*)result)->w15();
    fn_91_FE5C(self, taskId, valA, ownerId, valB);
    return 1;
}

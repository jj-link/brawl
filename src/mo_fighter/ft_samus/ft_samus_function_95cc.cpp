#pragma force_active on
struct KindObject {
    unsigned char padding[0x3C];
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4();
    virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9();
    virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14();
    virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24();
    virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29();
    virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34();
    virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39();
    virtual int getKind();
};
struct WorkModule {
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3();
    virtual int getInt(int);
};
struct ValueModule {
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4();
    virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8();
    virtual float getValue();
};
struct Modules {
    unsigned char padding0[0xC];
    ValueModule* value;
    unsigned char padding1[0x54];
    WorkModule* work;
};
struct Accesser {
    unsigned char padding0[8];
    KindObject* kind;
    unsigned char padding1[0xCC];
    Modules* modules;
};
extern "C" {
extern unsigned char g_ftCommonDataAccesser;
int* fn_27_1492A4(void*, int);
void fn_27_2FFA14(void*, float);
void fn_27_2FFA38(void*, int, float);
int fn_94_95CC(void* target, Accesser* accesser) {
    int* data = fn_27_1492A4(&g_ftCommonDataAccesser, accesser->kind->getKind());
    fn_27_2FFA14(target, (float)accesser->modules->work->getInt(0x10000042) / (float)*data);
    ValueModule* value = accesser->modules->value;
    int count = accesser->modules->work->getInt(0x10000042);
    float f = value->getValue();
    fn_27_2FFA38(target, count, f);
    return 0;
}
}

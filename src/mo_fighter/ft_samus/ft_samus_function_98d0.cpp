#pragma force_active on
struct KindObject {
    unsigned char padding[0x3C];
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual int getKind();
};

struct FloatObject {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual float getValue();
};

struct Modules {
    unsigned char padding[0xC];
    FloatObject* value;
};

struct Accesser {
    unsigned char padding0[8];
    KindObject* kind;
    unsigned char padding1[0xCC];
    Modules* modules;
};

struct CommonData {
    unsigned char padding[0xC];
    float a;
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser;
CommonData* fn_27_1493B0(void*, int);
void fn_27_2ED9DC(void*, float, float);

int fn_94_98D0(void* target, Accesser* accesser) {
    int kind = accesser->kind->getKind();
    CommonData* data = fn_27_1493B0(&g_ftCommonDataAccesser, kind);
    FloatObject* value = accesser->modules->value;
    float f = value->getValue();
    fn_27_2ED9DC(target, f, data->a);
    return 0;
}
}

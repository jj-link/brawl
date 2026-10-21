#pragma force_active on

struct CommonData {
    float rate;
    float unk_4;
    float unk_8;
    float unk_c;
};

class Owner {
    unsigned char padding[0x3C];
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual int getKind();
};

class Motion {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual float getRate(unsigned long id);
};

class RateSource {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual float getRate();
};

struct Modules {
    unsigned char padding[0xc];
    RateSource* rateSource;
    unsigned char padding2[0x54];
    Motion* motion;
};

struct Context {
    unsigned char padding0[8];
    Owner* owner;
    unsigned char padding1[0xCC];
    Modules* modules;
};

extern "C" {
    extern unsigned char g_ftCommonDataAccesser;
    CommonData* fn_27_14998C(void*, int);
    void fn_27_3A97F0(int, float, float, float);
}

extern "C" int fn_27_3A5E2C(int unused, int arg2, Context* context) {
    int kind = context->owner->getKind();
    CommonData* data = fn_27_14998C(&g_ftCommonDataAccesser, kind);
    float motionRate = context->modules->motion->getRate(0x21000004UL);
    float srcRate = context->modules->rateSource->getRate();
    fn_27_3A97F0(arg2, srcRate, data->unk_c, motionRate / data->rate);
    return 0;
}

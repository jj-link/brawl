#pragma force_active on
struct V3 { float x, y, z; };
struct Spd { float x, y; };
struct Energy { virtual void a(); virtual void b(); virtual unsigned long long getSpeed(); };
struct KMod {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void* getEnergy(int);
};
struct Post {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual float getLr();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void setRot(const V3*, int);
};
struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11();
    virtual float get(unsigned long);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void setFlag(unsigned long);
};
extern "C" {
extern unsigned char lbl_110_data_60DC[], lbl_110_data_168C[];
extern const float lbl_110_rodata_148, lbl_110_rodata_14C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
extern "C" void fn_110_1837C(void*, unsigned char* obj) {
    unsigned char* m = *(unsigned char**)(obj + 0xD8);
    Work* work = *(Work**)(m + 0x64);
    Post* post = *(Post**)(m + 0xC);
    KMod* k = *(KMod**)(m + 0x7C);
    Energy* e = (Energy*)__dynamic_cast(k->getEnergy(0), 0, lbl_110_data_60DC, lbl_110_data_168C, 1);
    Spd s;
    unsigned long long r = e->getSpeed();
    __memcpy(&s, &r, sizeof(s));
    if (lbl_110_rodata_148 == post->getLr()) {
        if (s.x <= lbl_110_rodata_14C) work->setFlag(0x22000003);
    } else {
        if (s.x >= lbl_110_rodata_14C) work->setFlag(0x22000003);
    }
    V3 v;
    v.x = -work->get(0x21000000);
    v.y = lbl_110_rodata_14C;
    v.z = lbl_110_rodata_14C;
    post->setRot(&v, 0);
}

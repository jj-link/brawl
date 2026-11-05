#pragma force_active on
struct V3 { float x, y, z; };
struct Spd { float x, y; };
struct Energy { virtual void a(); virtual void b(); virtual unsigned long long getSpeed(); };
struct KMod {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void* getEnergy(int);
};
class Class_70F0 {
public:
    virtual void fn_110_6E04(); virtual void fn_110_FF5C(); virtual void fn_110_12CAC(); virtual void fn_110_12CA4();
    virtual void fn_110_12C9C(); virtual void fn_110_12C94(); virtual void fn_110_12C8C(); virtual void fn_110_12C84();
    virtual void fn_110_12C7C(); virtual void fn_110_12C74(); virtual void fn_110_12C6C(); virtual void fn_110_12C64();
    virtual float fn_110_12C5C(unsigned long); virtual void fn_110_12C54(); virtual void fn_110_12C04(); virtual void fn_110_12C4C();
    virtual void fn_110_12C3C(); virtual void fn_110_12C2C(); virtual void fn_110_12C1C(unsigned long);
};
class Class_80F8 {
public:
    virtual void fn_110_15550(); virtual void fn_110_15548(); virtual void fn_110_15540(); virtual void fn_110_15538();
    virtual void fn_110_15530(); virtual void fn_110_15528(); virtual void fn_110_15520(); virtual void fn_110_15518();
    virtual void fn_110_1550C(); virtual float fn_110_15504(); virtual void fn_110_154FC(); virtual void fn_110_154F4();
    virtual void fn_110_154F0(); virtual void fn_110_154EC(); virtual void fn_110_154E8(); virtual void fn_110_154E4(const V3*, int);
    virtual void fn_110_154DC(); virtual void fn_110_154D8(); virtual void fn_110_154D0();
};
extern "C" {
extern unsigned char lbl_110_data_60DC[], lbl_110_data_168C[];
extern const float lbl_110_rodata_158, lbl_110_rodata_15C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
extern "C" void fn_110_187CC(void*, unsigned char* obj) {
    unsigned char* m = *(unsigned char**)(obj + 0xD8);
    Class_70F0* work = *(Class_70F0**)(m + 0x64);
    Class_80F8* post = *(Class_80F8**)(m + 0xC);
    KMod* k = *(KMod**)(m + 0x7C);
    Energy* e = (Energy*)__dynamic_cast(k->getEnergy(0), 0, lbl_110_data_60DC, lbl_110_data_168C, 1);
    Spd s;
    unsigned long long r = e->getSpeed();
    __memcpy(&s, &r, sizeof(s));
    if (lbl_110_rodata_158 == post->fn_110_15504()) {
        if (s.x <= lbl_110_rodata_15C) work->fn_110_12C1C(0x22000003);
    } else {
        if (s.x >= lbl_110_rodata_15C) work->fn_110_12C1C(0x22000003);
    }
    V3 v;
    v.x = -work->fn_110_12C5C(0x21000000);
    v.y = lbl_110_rodata_15C;
    v.z = lbl_110_rodata_15C;
    post->fn_110_154E4(&v, 0);
}
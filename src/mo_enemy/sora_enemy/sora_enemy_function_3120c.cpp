#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void wnemReport__FPCce(const char*, ...);
extern "C" char lbl_41_data_11F0[];
extern "C" char lbl_41_data_12A4[];
extern "C" char lbl_41_data_4302[];

#define P10(b) virtual void p##b##0(); virtual void p##b##1(); virtual void p##b##2(); virtual void p##b##3(); virtual void p##b##4(); virtual void p##b##5(); virtual void p##b##6(); virtual void p##b##7(); virtual void p##b##8(); virtual void p##b##9();

struct Hdr {
    int h0;
    int h1;
};

struct Iface : Hdr {
    virtual void p02();
    virtual void p03();
    virtual void p04();
    virtual void p05();
    virtual void p06();
    virtual void p07();
    virtual void p08();
    virtual void p09();
    P10(1) P10(2) P10(3) P10(4) P10(5) P10(6) P10(7)
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void m96(float, float, float, int);
    virtual void p97();
    virtual void p98();
    virtual void p99();
    virtual void m100(float, float, float, void*, int);
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void m110(unsigned char, int);
};

extern "C" void fn_41_3120C(char* wn) {
    char* p = *(char**)(*(char**)(*(char**)(wn + 0x6c) + 0xd8) + 0x10);
    short one = 1;
    Iface* obj = (Iface*)__dynamic_cast(p, 8, lbl_41_data_11F0, lbl_41_data_12A4, one);
    char* d = *(char**)(*(char**)(wn + 0x2184) + 0x34);
    obj->m110(*(unsigned char*)d, 0);
    d = *(char**)(*(char**)(wn + 0x2184) + 0x34);
    int st = *(unsigned char*)d;
    if (st == 2) {
        obj->m100(*(float*)(d + 0x8), *(float*)(d + 0xc), *(float*)(d + 0x10), *(void**)(d + 0x4), 0);
        wnemReport__FPCce(lbl_41_data_4302);
    } else if (st == 1) {
        obj->m96(*(float*)(d + 0x4), *(float*)(d + 0x8), *(float*)(d + 0xc), 0);
    }
}

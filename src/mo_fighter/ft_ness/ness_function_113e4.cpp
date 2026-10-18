#pragma force_active on
extern "C" void fn_27_169554(void);

struct Ness113Local {
    int kind;
    unsigned char flag;
    float value;
};

struct Ness113Iface {
    virtual void d0(void);
    virtual void d1(void);
    virtual void d2(void);
    virtual void d3(void);
    virtual void d4(void);
    virtual void d5(void);
    virtual void d6(void);
    virtual void d7(void);
    virtual void d8(void);
    virtual void d9(void);
    virtual void d10(void);
    virtual void d11(void);
    virtual void d12(void);
    virtual void d13(void);
    virtual void d14(void);
    virtual void d15(int, void*);
    virtual void d16(void);
    virtual int d17(unsigned int);
    virtual void d18(void);
    virtual void d19(void);
    virtual void d20(void);
    virtual void d21(void);
    virtual void d22(void);
    virtual void d23(void);
    virtual void d24(void);
    virtual void d25(void);
    virtual void d26(void);
    virtual void d27(void);
    virtual void d28(void);
    virtual void d29(void);
    virtual void d30(void);
    virtual void d31(void);
    virtual void d32(void);
    virtual void d33(void);
    virtual void d34(void);
    virtual void d35(void);
    virtual void d36(void);
    virtual void d37(void);
    virtual void d38(void);
    virtual void d39(void);
    virtual void d40(void);
    virtual void d41(void);
    virtual void d42(void);
    virtual void d43(void);
    virtual float d44(void);
};

extern "C" void fn_101_113E4(void*, unsigned char* obj) {
    fn_27_169554();

    Ness113Iface* a = *(Ness113Iface**)(*(unsigned char**)(obj + 0xd8) + 0x64);
    if (a->d17(0x22000003)) {
        Ness113Iface* b = *(Ness113Iface**)(*(unsigned char**)(obj + 0xd8) + 0x1c);
        float v = b->d44();

        Ness113Local l;
        l.kind = 0x456;
        l.flag = 0;
        l.value = v;

        Ness113Iface* c = *(Ness113Iface**)(*(unsigned char**)(obj + 0xd8) + 0x54);
        c->d15(7, &l);
    }
}

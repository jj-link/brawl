#pragma force_active on
extern "C" {
void fn_27_62CB0(void*, void*);
extern const float lbl_110_rodata_B0;
extern const float lbl_110_rodata_B4;
}

struct Iface {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15(int, void*);
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19(void*, void*);
};

struct Local {
    short a;
    int b;
    char c;
    float x, y, z;
};

extern "C" void fn_110_15344(void* self, void* p) {
    Local L;
    fn_27_62CB0(self, p);
    L.b = 0x842;
    L.c = 0;
    Iface* obj = *(Iface**)((char*)p + 0xd8);
    Iface* sub = *(Iface**)((char*)obj + 0x54);
    sub->s15(3, &L.b);
    L.x = lbl_110_rodata_B0;
    L.y = lbl_110_rodata_B4;
    L.z = lbl_110_rodata_B4;
    L.a = 1;
    obj = *(Iface**)((char*)p + 0xd8);
    sub = *(Iface**)((char*)obj + 0x7c);
    sub->s19(&L.x, &L.a);
}

#pragma force_active on
extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, unsigned long id, unsigned long index);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_95_AECC(void*);
extern const char lbl_95_data_5F8[];
extern const char lbl_95_data_36D8[];
}

struct Pad8 {
    char pad[8];
};

struct Obj : Pad8 {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void m26(void*, float*);
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void* m33(long);
};

struct Holder {
    char pad[4];
    Obj* owner;
};

extern "C" void fn_95_F0CC(void* unused, void* accesser) {
    float f[3];
    float v = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xbe6, 0);
    f[0] = v;
    f[1] = v;
    f[2] = v;
    Holder* h = *(Holder**)((char*)accesser + 0xd8);
    Obj* owner = h->owner;
    void* r = owner->m33(0x12c);
    owner->m26(r, f);
    void* d = __dynamic_cast(*(void**)((char*)accesser + 0x8), 0x3c, lbl_95_data_5F8, lbl_95_data_36D8, 1);
    fn_95_AECC(d);
}

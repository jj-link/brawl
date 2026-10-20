#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_2208;

struct VA {
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
    virtual void s15();
    virtual int target();
};

struct VB {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void* target(int);
};

extern "C" void fn_27_16FB30(void*, char* obj) {
    VA* a = *(VA**)(*(char**)(obj + 0xd8) + 0x70);
    int r = a->target();
    if (r == 0x66) {
        VB* b = *(VB**)(*(char**)(obj + 0xd8) + 0x7c);
        char* res = (char*)__dynamic_cast(b->target(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
        *(float*)(res + 0xc) = lbl_27_rodata_2208;
    }
}

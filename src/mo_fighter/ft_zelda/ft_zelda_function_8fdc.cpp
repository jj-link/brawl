#pragma force_active on
struct SomeClass {
    unsigned int f00;
    unsigned int f04;
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
};

extern "C" void fn_104_8ADC(void*, void*, unsigned, void*, unsigned, void*, unsigned);

extern "C" void* fn_104_8FDC(void* work) {
    char* p = (char*)work;
    fn_104_8ADC(p + 0x1c0, work, 0x4d, p + 0x134, 0x20, p + 0x1b4, 0x3);
    ((SomeClass*)(p + 0x1c0))->v25();
    return work;
}

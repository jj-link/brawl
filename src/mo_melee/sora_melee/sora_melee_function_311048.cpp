#pragma force_active on

extern "C" {
    extern const float lbl_27_rodata_7468;
    extern const float lbl_27_rodata_746C;
    void fn_27_193378(void* obj, float f);
}

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float slot12(unsigned int a, float f);
};

extern "C" void fn_27_311048(void* unused, unsigned char* obj, float f) {
    VObj* b = *(VObj**)(*(unsigned char**)(obj + 0xd8) + 0x64);
    float result = b->slot12(0x21000004, f);
    fn_27_193378(obj, lbl_27_rodata_7468 - lbl_27_rodata_746C * result);
}

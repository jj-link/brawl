#pragma force_active on
typedef unsigned int u32;

extern "C" {
    extern const float lbl_27_rodata_2208;
    void fn_27_193378(void* obj);
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
    virtual float slot14(u32 a, float f);
};

extern "C" void fn_27_16F890(void* unused, unsigned char* obj, float f) {
    VObj* b = *(VObj**)(*(unsigned char**)(obj + 0xd8) + 0x64);
    float r = b->slot14(0x21000004, f);
    if (lbl_27_rodata_2208 != r) {
        fn_27_193378(obj);
    }
}

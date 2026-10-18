#pragma force_active on
extern "C" {
extern const char lbl_102_data_6014[];
extern const char lbl_102_data_14F4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* v6(int);
    virtual void v7();
    virtual void v8();
    virtual float v9();
};

extern "C" void fn_102_16C18(void*, unsigned char* self) {
    VObj* a = *(VObj**)(*(unsigned char**)(self + 0xd8) + 0x7c);
    void* obj = a->v6(0);
    float* inner = (float*)__dynamic_cast(obj, 0, lbl_102_data_6014, lbl_102_data_14F4, 1);
    VObj* b = *(VObj**)(*(unsigned char**)(self + 0xd8) + 0xc);
    float v = b->v9();
    if (v != inner[0x38 / 4]) {
        inner[0x44 / 4] = -inner[0x44 / 4];
        inner[0x38 / 4] = v;
    }
}

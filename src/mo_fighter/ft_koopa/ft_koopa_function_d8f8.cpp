#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_102_data_6014[], lbl_102_data_14F4[];
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

extern "C" void fn_102_D8F8(void* unused, void* self) {
    unsigned char* s = reinterpret_cast<unsigned char*>(self);
    VObj* a = *reinterpret_cast<VObj**>(*reinterpret_cast<unsigned char**>(s + 0xd8) + 0x7c);
    void* inner = a->v6(0);
    unsigned char* obj = reinterpret_cast<unsigned char*>(
        __dynamic_cast(inner, 0, lbl_102_data_6014, lbl_102_data_14F4, 1));
    VObj* b = *reinterpret_cast<VObj**>(*reinterpret_cast<unsigned char**>(s + 0xd8) + 0x0c);
    float f = b->v9();
    if (f != *reinterpret_cast<float*>(obj + 0x38)) {
        float neg = -*reinterpret_cast<float*>(obj + 0x44);
        *reinterpret_cast<float*>(obj + 0x44) = neg;
        *reinterpret_cast<float*>(obj + 0x38) = f;
    }
}

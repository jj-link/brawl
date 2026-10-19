#pragma force_active on
extern "C" const float lbl_113_rodata_64;
extern "C" float* fn_113_18AAC(float* dst, const float* src, float z);

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(float* p);
};

extern "C" void fn_113_18A54(void* self) {
    char* p = *(char**)((char*)self + 0x60);
    p = *(char**)(p + 0xd8);
    VObj* obj = *(VObj**)(p + 0xc);
    float tmp[2];
    float* src;
    float* res = fn_113_18AAC(tmp, src, lbl_113_rodata_64);
    obj->v5(res);
}

#pragma force_active on
extern "C" {
extern float lbl_16_rodata_180;
extern const float lbl_16_rodata_128;
void setFrameNode__8MuObjectFf(void*, float);
}

class VObj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8(float) = 0;
};

extern "C" void fn_16_35E0(unsigned char* self) {
    self = *(unsigned char**)(self + 0x40);
    setFrameNode__8MuObjectFf(self, lbl_16_rodata_180);
    VObj* child = *(VObj**)(*(unsigned char**)(self + 0x14) + 0xC);
    child->v8(lbl_16_rodata_128);
}

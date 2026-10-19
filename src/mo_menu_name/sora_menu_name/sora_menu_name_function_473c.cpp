#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
extern const float lbl_16_rodata_214;
extern const float lbl_16_rodata_128;
void setFrameNode__8MuObjectFf(void* obj, float frame);
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
    virtual void v8(float frame) = 0;
};

extern "C" void fn_16_473C(u8* self) {
    if (*(s32*)(self + 0x98) != 2) {
        u8* obj = *(u8**)(self + 0x40);
        setFrameNode__8MuObjectFf(obj, lbl_16_rodata_214);
        VObj* child = *(VObj**)(*(u8**)(obj + 0x14) + 0xC);
        child->v8(lbl_16_rodata_128);
    }
}

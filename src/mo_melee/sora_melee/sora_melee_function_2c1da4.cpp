#pragma force_active on
typedef int s32;

extern "C" s32 fn_27_2C20E8(void*, s32, s32);

class SoraBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual s32 vf3();
};

extern "C" void fn_27_2C1DA4(SoraBase* self, s32* src) {
    s32 idx = self->vf3();
    s32 r = fn_27_2C20E8(self, idx - 1, -1);
    if (r >= 0) {
        *(s32*)((char*)self + r * 12 + 0xC) = *src;
    }
}

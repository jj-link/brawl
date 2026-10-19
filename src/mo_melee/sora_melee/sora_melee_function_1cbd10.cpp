#pragma force_active on
typedef unsigned int u32;

class fn_27_Base {
public:
    virtual void vf0();
    virtual u32* vf1(u32 arg);
};

extern "C" void fn_27_1CBD10(fn_27_Base* self, u32* src, u32 arg) {
    u32* dst = self->vf1(arg);
    *dst = *src;
}

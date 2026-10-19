#pragma force_active on
typedef unsigned int u32;

class fn_27_Base {
public:
    virtual void vf0();
    virtual u32* vf1(void* p);
    virtual void vf2();
};

extern "C" void fn_27_FBB94(fn_27_Base* self, u32* src, void* arg) {
    u32* dst = self->vf1(arg);
    *dst = *src;
}

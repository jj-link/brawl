#pragma force_active on
typedef unsigned int u32;

class stFooBase {
public:
    virtual ~stFooBase();
    virtual u32* vf1(void* p);
};

extern "C" void fn_27_F4EC8(stFooBase* self, u32* src, void* p) {
    u32* dst = self->vf1(p);
    *dst = *src;
}

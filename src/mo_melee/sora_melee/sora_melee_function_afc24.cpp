#pragma force_active on
typedef unsigned int u32;

class fnBase {
public:
    virtual void f0();
    virtual u32* f1(void* arg);
};

extern "C" void fn_27_AFC24(fnBase* self, u32* src, void* arg) {
    u32* dst = self->f1(arg);
    *dst = *src;
}

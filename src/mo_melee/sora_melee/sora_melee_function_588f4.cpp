#pragma force_active on
extern "C" const float lbl_27_rodata_734[];

typedef unsigned long u32;

struct Holder {
    virtual void* vf0();
    virtual void* vf1();
    virtual void* vf2();
    virtual void* vf3();
};

class soControllerModuleImpl {
public:
    void endClatter(u32);
private:
    char m_pad[0x10];
    Holder* m_holder;
};

void soControllerModuleImpl::endClatter(u32) {
    float* p = (float*)m_holder->vf1();
    *p = lbl_27_rodata_734[0];
}

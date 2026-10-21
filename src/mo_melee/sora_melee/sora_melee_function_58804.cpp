#pragma force_active on
typedef unsigned long u32;

extern "C" const float lbl_27_rodata_734[];

struct Holder {
    virtual void* vf0();
    virtual float* vf1(u32);
    virtual void* vf2();
    virtual void* vf3();
};

class soControllerModuleImpl {
public:
    void addClatterTime(float, u32);

private:
    char m_pad[0x10];
    Holder* m_holder;
};

void soControllerModuleImpl::addClatterTime(float time, u32 index) {
    float* p = m_holder->vf1(index);
    *p += time;

    p = m_holder->vf1(index);
    if (*p < lbl_27_rodata_734[0]) {
        p = m_holder->vf1(index);
        *p = lbl_27_rodata_734[0];
    }
}

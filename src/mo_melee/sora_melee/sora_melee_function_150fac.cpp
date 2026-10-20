#pragma force_active on
class soBase {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual int vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
};

class soOwner {
public:
    unsigned char m_pad[0x14c];
    soBase* m_base;
};

extern "C" {
int fn_27_150FAC(soOwner* self) {
    return self->m_base->vf22();
}
}

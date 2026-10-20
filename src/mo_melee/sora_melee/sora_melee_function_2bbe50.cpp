#pragma force_active on
extern "C" int fn_27_2BC3B0(void*);

class soWorkBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual unsigned int vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
};

struct soWorkElem {
    int a, b, c, d, e;
};

class soWorkArray : public soWorkBase {
public:
    int m_pad[2];
    soWorkElem m_elems[1];
};

extern "C" {
void* fn_27_2BBE50(soWorkArray* self) {
    int idx = fn_27_2BC3B0(self);
    if (self->vf6() != 1 && idx >= 0) {
        self->vf15();
    }
    return &self->m_elems[idx];
}
}

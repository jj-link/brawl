#pragma force_active on
class fnInner {
public:
    virtual int vfn0();
    virtual int vfn1();
    virtual int vfn2();
    virtual int vfn3();
    virtual int vfn4();
    virtual int vfn5();
    virtual int vfn6();
    virtual int vfn7();
    virtual int vfn8();
    virtual void vfn9();
};

class fnOuter {
public:
    int m_unk0;
    fnInner* m_inner;
    int m_unk8;
    int m_count;
};

extern "C" void fn_27_1EF00(fnOuter* self) {
    if (self->m_inner && self->m_inner->vfn4() == 0) {
        self->m_inner->vfn7();
    } else if (self->m_count > 0) {
        self->m_count--;
    }
}

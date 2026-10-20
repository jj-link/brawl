#pragma force_active on
class IAnmObj {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual int f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
};

class soObj {
public:
    void* unk0;
    IAnmObj* m_anmObj;
    int unk8;
    int m_count;
};

extern "C" {
void fn_27_C75D8(soObj* self) {
    if (self->m_anmObj != 0 && self->m_anmObj->f6() == 0) {
        self->m_anmObj->f9();
    } else {
        if (self->m_count > 0) {
            self->m_count--;
        }
    }
}
}

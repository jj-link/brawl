#pragma force_active on
class soBase {
public:
    virtual bool f0();
    virtual bool f1();
    virtual bool f2();
    virtual bool f3();
    virtual bool f4();
    virtual bool f5();
};

extern "C" bool fn_27_CDEF0(soBase* self) {
    return !self->f3();
}

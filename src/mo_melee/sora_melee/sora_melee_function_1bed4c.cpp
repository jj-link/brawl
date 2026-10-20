#pragma force_active on
class soOuterBase {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
};

class soHolder {
public:
    int m_pad[4];
};

class soMulti : public soHolder, public soOuterBase {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
};

extern "C" {
void fn_27_1BED4C(soMulti* self) {
    soOuterBase& r = *self;
    r.g1();
}
}

#pragma force_active on
class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_77_5F68(Base* p) {
    return !p->v3();
}

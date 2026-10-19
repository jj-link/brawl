#pragma force_active on
struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_68_9E14(Base* self) {
    return self->v3() == 0;
}

#pragma force_active on
struct soBaseWork {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
};

extern "C" {
    bool fn_27_84E64(soBaseWork* self) {
        return !self->v4();
    }
}

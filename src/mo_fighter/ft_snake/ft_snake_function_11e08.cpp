#pragma force_active on
struct Interface {
    virtual int a();
    virtual int b();
    virtual int c();
    virtual int d();
};

extern "C" bool fn_122_11E08(Interface* self) {
    return !self->d();
}

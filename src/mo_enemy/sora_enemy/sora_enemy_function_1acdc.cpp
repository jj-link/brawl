#pragma force_active on
struct Base {
    virtual int a();
    virtual int b();
};

extern "C" int fn_41_1ACDC(Base* obj) {
    return obj->b();
}

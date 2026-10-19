#pragma force_active on
struct Base {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int get();
};

extern "C" bool fn_41_1AC68(Base* object) {
    return !object->get();
}

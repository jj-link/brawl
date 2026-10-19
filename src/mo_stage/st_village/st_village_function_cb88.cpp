#pragma force_active on
struct Base {
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int query();
};

extern "C" bool fn_70_CB88(Base* object) {
    return object->query() == 0;
}

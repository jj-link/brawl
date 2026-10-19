#pragma force_active on
struct Base {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
};

extern "C" bool fn_70_8EEC(Base* object) {
    return object->f3() == 0;
}

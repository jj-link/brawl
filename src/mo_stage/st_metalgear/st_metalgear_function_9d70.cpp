#pragma force_active on
struct Object {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int method();
};

extern "C" bool fn_71_9D70(Object* object) {
    return object->method() == 0;
}

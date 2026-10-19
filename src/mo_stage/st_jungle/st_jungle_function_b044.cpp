#pragma force_active on
struct Interface {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual bool method();
};

extern "C" bool fn_51_B044(Interface* object) {
    return !object->method();
}

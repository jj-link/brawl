#pragma force_active on
struct Interface {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int method();
};

extern "C" int fn_67_8AF0(Interface* object) {
    return object->method() == 0;
}

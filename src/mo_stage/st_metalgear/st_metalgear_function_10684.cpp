#pragma force_active on
struct Interface {
    virtual int method0();
    virtual int method1();
    virtual int method2();
    virtual int method3();
};

extern "C" int fn_71_10684(Interface* object) {
    return object->method3() == 0;
}

#pragma force_active on
class Interface {
public:
    virtual int method0();
    virtual int method1();
    virtual int method2();
    virtual int method3();
};

extern "C" bool fn_27_CBBE0(Interface* self) {
    return self->method3() == 0;
}

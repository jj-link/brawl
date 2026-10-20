#pragma force_active on
class Object {
    unsigned char unused[12];

public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void invoke(int, int, int);
};

extern "C" void fn_27_1D6E58(void*, Object* object) {
    object->invoke(1, 0x18, 0);
}

#pragma force_active on
class Interface {
public:
    virtual int method0();
    virtual int method1();
    virtual int method2();
    virtual int method3();
};

struct Object {
    char padding[0x10];
    Interface member;
};

extern "C" int fn_27_1B1468(Object* object) {
    return object->member.method3();
}

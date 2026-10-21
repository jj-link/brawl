#pragma force_active on
class Work {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void call();
};

struct Object {
    unsigned char padding[0x10];
    Work work;
};

extern "C" void fn_27_1E5654(Object* object) {
    object->work.call();
}

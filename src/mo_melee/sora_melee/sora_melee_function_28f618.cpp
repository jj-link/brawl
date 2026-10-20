#pragma force_active on
struct Object;

struct DispatchBase {
    unsigned int data[2];
};

struct Dispatch : DispatchBase {
    virtual void unused0() = 0;
    virtual void unused1() = 0;
    virtual void unused2() = 0;
    virtual void unused3() = 0;
    virtual void unused4() = 0;
    virtual void unused5() = 0;
    virtual void unused6() = 0;
    virtual void unused7() = 0;
    virtual void unused8() = 0;
    virtual void unused9() = 0;
    virtual void unused10() = 0;
    virtual void unused11() = 0;
    virtual void unused12() = 0;
    virtual void unused13() = 0;
    virtual void unused14() = 0;
    virtual void unused15() = 0;
    virtual void unused16() = 0;
    virtual void unused17() = 0;
    virtual void unused18() = 0;
    virtual void unused19() = 0;
    virtual void unused20() = 0;
    virtual void unused21() = 0;
    virtual void unused22() = 0;
    virtual void unused23() = 0;
    virtual void unused24() = 0;
    virtual void unused25() = 0;
    virtual void unused26() = 0;
    virtual void method(Object*, unsigned int) = 0;
};

struct Object {
    unsigned char padding[0x8D0];
    Dispatch* dispatch;
};

extern "C" void fn_27_28F618(Object* obj, unsigned int arg) {
    obj->dispatch->method(obj, arg);
}

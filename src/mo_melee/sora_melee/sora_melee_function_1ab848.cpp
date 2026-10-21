#pragma force_active on
class Interface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void invoke();
};

struct Object {
    unsigned char padding[12];
    Interface member;
};

extern "C" void fn_27_1AB848(Object* object) {
    object->member.invoke();
}

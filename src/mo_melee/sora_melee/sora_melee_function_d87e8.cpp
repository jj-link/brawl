#pragma force_active on
class SubObject {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void call();
};

struct Object {
    char pad[16];
    SubObject sub;
};

extern "C" void fn_27_D87E8(Object* object) {
    object->sub.call();
}

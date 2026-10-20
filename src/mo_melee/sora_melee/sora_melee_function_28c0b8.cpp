#pragma force_active on
struct Object;

class Delegate {
public:
    int padding[2];

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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void call(Object*, int, int);
};

struct Object {
    char padding[0x8d0];
    Delegate* delegate;
};

extern "C" void fn_27_28C0B8(Object* self, int a, int b) {
    self->delegate->call(self, a, b);
}

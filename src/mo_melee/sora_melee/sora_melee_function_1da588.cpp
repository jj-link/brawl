#pragma force_active on
class Target {
public:
    unsigned char padding[8];
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
    virtual void call();
};

struct Level2 {
    unsigned char padding[0x9C];
    Target* target;
};

struct Level1 {
    unsigned char padding[0xD8];
    Level2* next;
};

struct Object {
    unsigned char padding[0x60];
    Level1* next;
};

extern "C" void fn_27_1DA588(Object* object) {
    object->next->next->target->call();
}

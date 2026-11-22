#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual float slot8() const;
    unsigned char pad[0xcc];
    unsigned char value;

    int getValue() const { return value; }
};

extern "C" int fn_801ADB40(const Object_vptr_0* b, const Object_vptr_0* a) {
    int y = a->getValue();
    int x = b->getValue();
    if (x == y) {
        float fa = a->slot8();
        return b->slot8() < fa;
    }
    return x < y;
}

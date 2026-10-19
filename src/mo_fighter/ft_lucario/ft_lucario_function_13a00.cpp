#pragma force_active on
namespace {
struct ObjectPrefix {
    unsigned char padding[0x3C];
};

class Object : private ObjectPrefix {
public:
    virtual ~Object();
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4C() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual void slot58() = 0;
    virtual void slot5C() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual void slot68() = 0;
    virtual void slot6C() = 0;
    virtual void slot70() = 0;
    virtual void slot74() = 0;
    virtual void slot78() = 0;
    virtual void slot7C() = 0;
    virtual void slot80() = 0;
    virtual void slot84() = 0;
    virtual void slot88() = 0;
    virtual void slot8C() = 0;
    virtual void slot90() = 0;
    virtual void slot94() = 0;
    virtual void slot98() = 0;
    virtual void slot9C() = 0;
    virtual void slotA0() = 0;
    virtual void slotA4() = 0;
    virtual void slotA8() = 0;
    virtual void target() = 0;
};
}

extern "C" void fn_118_13A00(Object* object) {
    object->target();
}

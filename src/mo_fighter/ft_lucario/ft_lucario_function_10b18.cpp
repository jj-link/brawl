#pragma force_active on
struct VirtualTarget {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C(float, unsigned int);
};

struct Inner {
    unsigned char pad[0x64];
    VirtualTarget* target;
};

struct Outer {
    unsigned char pad[0xd8];
    Inner* inner;
};

extern "C" const float lbl_118_rodata_98;

extern "C" void fn_118_10B18(void*, Outer* object) {
    object->inner->target->slot3C(lbl_118_rodata_98, 0x21000004);
}

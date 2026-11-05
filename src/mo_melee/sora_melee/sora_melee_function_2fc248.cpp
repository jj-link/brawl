#pragma force_active on
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5(int, unsigned int);
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
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual int slot32(unsigned int);
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39(int);
};
struct Inner {
    char pad0[0x64];
    soNullable* work;
    char pad1[8];
    soNullable* o70;
    char pad2[0x14];
    soNullable* o88;
};
struct Outer {
    char pad[0xd8];
    Inner* inner;
};
extern "C" void fn_27_2FC248(void* unused, Outer* obj) {
    if (obj->inner->o70->slot32(0) != 0x11a) {
        unsigned int base = 0x10000000;
        soNullable* w = obj->inner->work;
        int val = w->slot4(base + 0x41);
        w->slot5(val, base + 0x42);
        obj->inner->work->slot5(0, base + 0x41);
    }
    obj->inner->o88->slot39(0x1a);
}
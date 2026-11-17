#pragma force_active on
extern "C" void fn_8004765C(void*, void*, void*, void*);

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
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual unsigned int slot15();
};

class Prefix8 {
public:
    char pad[8];
};

struct Outer;
class soModelModuleImpl : public Prefix8 {
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
    virtual void slot13();
    virtual void* slot14(int);
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
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void* slot45(int);

    void preShadowCalcView();

    void* fieldC;
    char pad10[0xa0];
    void* fieldB0;
    char padB4[0x14];
    Outer* fieldC8;
};

struct Inner {
    char pad[0xa4];
    Object_vptr_0* object;
};

struct Outer {
    char pad[0xd8];
    Inner* inner;
};

void soModelModuleImpl::preShadowCalcView() {
    if (fieldC8->inner->object->slot15() == 1) {
        void* second;
        void* result = slot14(1);
        second = fieldC;
        void* other = slot45(1);
        fn_8004765C(result, second, fieldB0, other);
    }
}

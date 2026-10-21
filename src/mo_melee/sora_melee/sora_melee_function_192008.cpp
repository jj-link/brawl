#pragma force_active on
class Module20 {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void call44(int, int, int) = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void call50(int, int) = 0;
};

class Module10 {
    int pad00[2];

public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void call54(int, int) = 0;
};

struct Modules {
    char pad00[0x10];
    Module10* module10;
    char pad14[0xC];
    Module20* module20;
};

struct Object {
    char pad00[0xD8];
    Modules* modules;
};

extern "C" void fn_27_192008(void*, Object* object) {
    object->modules->module20->call50(3, 0);
    object->modules->module20->call44(0, 0, 0);
    object->modules->module10->call54(0, 0);
}

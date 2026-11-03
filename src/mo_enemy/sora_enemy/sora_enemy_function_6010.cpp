#pragma force_active on
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(unsigned int);
};

class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
    virtual void fn_41_350D4();
    virtual void fn_41_350E4();
    virtual void fn_41_350EC();
    virtual void fn_41_350F0();
    virtual void fn_41_350F4();
    virtual void fn_41_350F8();
    virtual void fn_41_350FC();
    virtual void fn_41_35108();
    virtual void fn_41_3510C();
    virtual void fn_41_13638(unsigned int);
};

struct Fn41Module {
    unsigned char pad00[0x44];
    soNullable* field_44;
    unsigned char pad48[0x1C];
    Class_6E20* field_64;
};

struct Fn41Object {
    unsigned char pad00[0x1B4];
    Fn41Module* field_1B4;
    unsigned char pad1B8[0x1108 - 0x1B8];
    unsigned char field_1108[4];
};

extern "C" void fn_27_553C(Fn41Object*);
extern "C" void* fn_41_5E20();
extern "C" unsigned int fn_27_5BEA8(void*);
extern "C" void fn_41_2A40C(void*);

extern "C" void fn_41_6010(Fn41Object* obj) {
    Class_6E20* work = obj->field_1B4->field_64;
    fn_27_553C(obj);
    if (fn_27_5BEA8(fn_41_5E20()) == 1U) {
        if (obj->field_1B4->field_44->slot9() == 0) {
            work->fn_41_13638(0x12000005);
            fn_41_2A40C(obj->field_1108);
            work->fn_41_13638(0x1200000E);
        }
        work->fn_41_13638(0x12000009);
        work->fn_41_13638(0x1200000D);
        work->fn_41_13638(0x12000012);
        work->fn_41_13638(0x12000013);
        work->fn_41_13638(0x22000007);
        work->fn_41_13638(0x22000006);
        work->fn_41_13638(0x22000005);
    }
}

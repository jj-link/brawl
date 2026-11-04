#pragma force_active on
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual ~soNullable();
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
    virtual unsigned int slot20();
    virtual void slot21();
};
class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual soNullable** fn_27_14068(int);
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual int fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80();
    virtual void fn_27_14B88();
    virtual void fn_27_16A70();
    virtual void fn_27_16AB8();
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20();
};
extern "C" void fn_27_1E83A4(Class_1250* arg0) {
    while (!arg0->fn_27_14134()) {
        soNullable* obj = *arg0->fn_27_14068(0);
        if (obj) {
            if (obj->slot20() == 1U)
                obj->slot21();
            delete obj;
        }
        arg0->fn_27_14A28();
    }
}
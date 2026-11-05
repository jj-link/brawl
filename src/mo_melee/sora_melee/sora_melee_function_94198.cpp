#pragma force_active on

extern "C" void OSReport(const char*, ...);
extern const char lbl_27_data_142A8;

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(int, int);
    virtual void slot10();
};

class SelfVt {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual int fn_27_94000();  // offset 0x50
};

class Class_14370 {
public:
    virtual void fn_27_93100();
    virtual soNullable** fn_27_9329C(int);
    virtual void fn_27_932A0();
    virtual int getCount();  // offset 0x14: fn_27_93778
    virtual void fn_27_95264();
};

struct Object : SelfVt {
    char pad[0x28];
    Class_14370* array;
};

extern "C" void fn_27_94198(Object* self, int kind, int a, int b) {
    if (self->fn_27_94000() == 0) {
        OSReport(&lbl_27_data_142A8);
        return;
    }
    for (int i = 0; i < self->array->getCount(); i++) {
        if (*self->array->fn_27_9329C(i) != 0) {
            if (kind == (*self->array->fn_27_9329C(i))->slot6()) {
                (*self->array->fn_27_9329C(i))->slot9(a, b);
            }
        }
    }
}

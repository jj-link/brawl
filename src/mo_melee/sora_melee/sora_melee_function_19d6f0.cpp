#include <so/so_array_vector_calculator.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_38988[];
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_CD5E0(void*);
void fn_27_46700(void*, short);
}

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual bool slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(int);
    virtual void slot11();
    virtual void slot12();
    virtual long slot13();
    virtual bool slot14();
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
    virtual long slot27();
    virtual long slot28();

    void* p4;
    unsigned int f8;
    char arr[0x480];
};

extern "C" soNullable* fn_27_19D6F0(soNullable* self, int a, int arg2) {
    *(void**)self = lbl_27_data_38988;
    self->p4 = lbl_27_data_38988 + 0x48;
    self->f8 &= 0xFFFF;

    __construct_array(self->arr, fn_27_CD5E0,
                      (void (*)(void*))fn_27_46700, 0x60, 12);

    bool t14;
    long t13;
    long t27;
    long t28;
    t28 = self->slot28();
    t27 = self->slot27();
    t13 = self->slot13();
    t14 = self->slot14();
    bool t4 = self->slot4();

    int n = soArrayVectorCalculator::resize(
        *(soArrayVectorCalcInterface*)&self->p4, a, t4, t14, t13, t27, t28);

    for (int i = 0; i < n; i++) {
        self->slot10(arg2);
    }

    return self;
}

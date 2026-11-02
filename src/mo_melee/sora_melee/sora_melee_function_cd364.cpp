#pragma force_active on
#include <so/so_array_vector_calculator.h>

extern "C" {
extern char lbl_27_data_1D938[];
void* fn_27_CD2F8(void*);
void* fn_27_4D8E0(void*, short);
void __construct_array(void*, void* (*)(void*), void* (*)(void*, short), unsigned long, int);
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
    virtual s32 slot13();
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
    virtual s32 slot27();
    virtual s32 slot28();

    void* p4;
    unsigned int f8;
    char arr[0x60];
};

extern "C" soNullable* fn_27_CD364(soNullable* self, s32 size, int element) {
    unsigned int flags = self->f8;
    *(void**)self = lbl_27_data_1D938;
    self->p4 = lbl_27_data_1D938 + 0x48;
    self->f8 = flags & 0x01FFFFFF;

    __construct_array(self->arr, fn_27_CD2F8, fn_27_4D8E0, 0x60, 1);

    bool t31;
    s32 t30;
    s32 t29;
    s32 t28;
    t28 = self->slot28();
    t29 = self->slot27();
    t30 = self->slot13();
    t31 = self->slot14();
    bool n = self->slot4();

    int count = soArrayVectorCalculator::resize(
        *(soArrayVectorCalcInterface*)&self->p4, size, n, t31, t30, t29, t28);

    for (int i = 0; i < count; i++) {
        self->slot10(element);
    }

    return self;
}

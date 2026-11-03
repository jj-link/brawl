#pragma force_active on
#include <so/so_array_vector_calculator.h>
#include <so/collision/so_collision_group.h>

extern "C" {
extern char lbl_27_data_1D938[];
extern char lbl_27_data_46F8[];
void fn_27_4D800(void*, int);
void* fn_27_4D8E0(void*, short);
void* fn_27_CD2F8(void*);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
void __construct_array(void*, void* (*)(void*), void* (*)(void*, short), unsigned long, int);
void fn_27_4DCA4(void*, void*, void*, unsigned char, void*, int);
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
    virtual void slot10(void*);
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
    void* p6c;
    void* p70;
    unsigned int a:4;
    unsigned int b:2;
    unsigned int c:1;
    unsigned int rest:25;
    char groups[0x78];
};

extern "C" soNullable* fn_27_2E6F0C(soNullable* self, void* b, void* c, unsigned char d) {
    char buf[0x60];
    fn_27_4D800(buf, 0);
    unsigned int flags = self->f8;
    *(void**)self = lbl_27_data_1D938;
    self->p4 = lbl_27_data_1D938 + 0x48;
    self->f8 = flags & 0x01FFFFFF;
    __construct_array(self->arr, fn_27_CD2F8, fn_27_4D8E0, 0x60, 1);
    bool t14;
    s32 t13;
    s32 t27;
    s32 t28;
    t28 = self->slot28();
    t27 = self->slot27();
    t13 = self->slot13();
    t14 = self->slot14();
    bool t4 = self->slot4();
    int count = soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&self->p4, 1, t4, t14, t13, t27, t28);
    for (int i = 0; i < count; i++) self->slot10(buf);
    fn_27_4D8E0(buf, -1);
    self->p6c = lbl_27_data_46F8;
    self->p70 = lbl_27_data_46F8 + 0x48;
    self->a = 0;
    self->b = 1;
    self->c = 0;
    __construct_array(self->groups, (void* (*)(void*))__ct__16soCollisionGroupFv, (void* (*)(void*, short))fn_27_37D3C, 0x78, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&self->p70, 1, 1);
    fn_27_4DCA4((char*)self + 0xF0, b, c, d, self, 1);
    return self;
}
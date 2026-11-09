#pragma force_active on
extern "C" {
extern char lbl_27_data_3E748[];
void __construct_array(void*, void* (*)(void*), void* (*)(void*, short), int, int);
void* __ct__21soCollisionAttackPartFv(void*);
void* __dt__21soCollisionAttackPartFv(void*, short);
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
    void*, void*, int, int, int, int, int);
}
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(int);
    virtual void slot11();
    virtual void slot12();
    virtual int slot13();
    virtual int slot14();
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
    virtual int slot27();
    virtual int slot28();
    void* p4;
    unsigned int f8;
    char arr[0x90];
};
extern "C" Object_vptr_0* fn_27_19C940(Object_vptr_0* self, void* arg1, int arg2) {
    *(void**)self = lbl_27_data_3E748;
    self->p4 = lbl_27_data_3E748 + 0x48;
    self->f8 &= 0x01FFFFFF;
    __construct_array(self->arr, __ct__21soCollisionAttackPartFv,
                      __dt__21soCollisionAttackPartFv, 0x90, 1);
    int t31;
    int t30;
    int t29;
    int t28;
    t28 = self->slot28();
    t29 = self->slot27();
    t30 = self->slot13();
    t31 = self->slot14();
    int n = self->slot4();
    int cnt = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
        &self->p4, arg1, n, t31, t30, t29, t28);
    for (int i = 0; i < cnt; i++) {
        self->slot10(arg2);
    }
    return self;
}
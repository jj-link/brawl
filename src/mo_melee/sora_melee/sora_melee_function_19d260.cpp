#pragma force_active on
#include <so/collision/so_collision_attack_part.h>
#include <so/so_array_vector_calculator.h>

extern "C" {
extern char lbl_27_data_38B78[];
void __construct_array(void*, void* (*)(void*), void* (*)(void*, short), int, int);
void* __ct__21soCollisionAttackPartFv(void*);
void* __dt__21soCollisionAttackPartFv(void*, short);
}

class CollisionAttackArray {
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
    virtual void slot10(const soCollisionAttackPart&);
    virtual void slot11();
    virtual void slot12();
    virtual int slot13();
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
    virtual int slot27();
    virtual int slot28();

    void* p4;
    unsigned int f8;
    soCollisionAttackPart arr[8];
};

extern "C" CollisionAttackArray* fn_27_19D260(CollisionAttackArray* self, int size, const soCollisionAttackPart& element) {
    *(void**)self = lbl_27_data_38B78;
    self->p4 = lbl_27_data_38B78 + 0x48;
    self->f8 &= 0xFFFF;
    __construct_array(self->arr, __ct__21soCollisionAttackPartFv,
                      __dt__21soCollisionAttackPartFv, 0x90, 8);
    bool t31;
    int t30;
    int t29;
    int t28;
    t28 = self->slot28();
    t29 = self->slot27();
    t30 = self->slot13();
    t31 = self->slot14();
    bool n = self->slot4();
    int cnt = soArrayVectorCalculator::resize(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->p4),
        size, n, t31, t30, t29, t28);
    for (int i = 0; i < cnt; i++) {
        self->slot10(element);
    }
    return self;
}

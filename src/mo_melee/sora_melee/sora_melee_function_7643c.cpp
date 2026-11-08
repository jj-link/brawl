#pragma force_active on

#include <types.h>
#include <so/so_array_vector_calculator.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual s32 slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
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
    virtual s32* slot26(s32);
    virtual s32 slot27();
    virtual s32 slot28();
    virtual void slot29(s32);

    s32 calc;
};

extern "C" void fn_27_7643C(Object_vptr_0* self, s32 index, const s32* src) {
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    a = self->slot28();
    b = self->slot27();
    c = self->slot13();
    d = self->slot3();
    bool e = self->slot14();
    s32 pos = soArrayVectorCalculator::insert(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc), index, e, d, c, b, a);
    s32* dst = self->slot26(pos);
    *dst = *src;
    self->slot29(self->slot3() + 1);
}

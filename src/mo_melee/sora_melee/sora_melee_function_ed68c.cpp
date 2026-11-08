#include <types.h>
#include <so/so_array_vector_calculator.h>
#pragma force_active on

struct Item {
    s32 a0;
    s32 a4;
    s32 a8;
    s32 aC;
    s32 a10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    u8 b24;
    s32 w28;
};

class soNullable {
public:
    virtual void isNull();
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
    virtual Item* slot26(s32);
    virtual s32 slot27();
    virtual s32 slot28();
    virtual void slot29(s32);
    s32 calc;
};

extern "C" void fn_27_ED68C(soNullable* self, s32 index, const Item* src) {
    s32 d, c, b, a;
    a = self->slot28();
    b = self->slot27();
    c = self->slot13();
    d = self->slot3();
    s32 pos = soArrayVectorCalculator::insert(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc), index, self->slot14(), d,
        c, b, a);
    Item* dst = self->slot26(pos);
    dst->a0 = src->a0;
    dst->a4 = src->a4;
    dst->a8 = src->a8;
    dst->aC = src->aC;
    dst->a10 = src->a10;
    dst->f14 = src->f14;
    dst->f18 = src->f18;
    dst->f1C = src->f1C;
    dst->f20 = src->f20;
    dst->b24 = src->b24;
    dst->w28 = src->w28;
    self->slot29(self->slot3() + 1);
}

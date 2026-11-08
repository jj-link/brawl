#pragma force_active on
#include <types.h>
#include <so/so_array_vector_calculator.h>

struct Rec;
extern "C" void fn_27_77588(Rec*, const Rec*);
struct Rec {
    unsigned char base[8];
    int field8;
    short fieldC;
    short fieldE;
    Rec& operator=(const Rec& value) {
        fn_27_77588(this, &value);
        field8 = value.field8;
        fieldC = value.fieldC;
        fieldE = value.fieldE;
        return *this;
    }
};
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
    virtual Rec* slot26(s32);
    virtual s32 slot27();
    virtual s32 slot28();
    virtual void slot29(s32);
    s32 calc;
};
extern "C" void fn_27_DE454(Object_vptr_0* self, s32 index, const Rec* src) {
    s32 pos = soArrayVectorCalculator::insert(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc), index, self->slot14(), self->slot3(),
        self->slot13(), self->slot27(), self->slot28());
    Rec* dst = self->slot26(pos);
    *dst = *src;
    self->slot29(self->slot3() + 1);
}
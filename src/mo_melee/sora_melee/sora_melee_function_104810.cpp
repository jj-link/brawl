#pragma force_active on
#include <types.h>
#include <so/so_array_vector_calculator.h>
struct Item { s32 a; s32 b; s16 c; s16 d; };
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
extern "C" void fn_27_104810(soNullable* self, s32 index, const Item* src) {
 s32 pos = soArrayVectorCalculator::insert(
  *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc),
  index, self->slot14(), self->slot3(), self->slot13(),
  self->slot27(), self->slot28());
 *self->slot26(pos) = *src;
 self->slot29(self->slot3() + 1);
}
#include <types.h>
#pragma force_active on
struct Elem { u32 a, b; };
class Class_C80 {
public:
 virtual void fn_27_FEE4();
 virtual Elem* fn_27_FF68(int);
 virtual void fn_27_FFAC();
 virtual int fn_27_FFF0();
};
struct Outer { char pad[0x1c]; Class_C80* array; char pad2[4]; u8 flag; };
extern "C" int fn_27_118(Outer* a, Outer* b, int flag) {
 if (a->flag == 1 && b->flag == 1) {
  if (flag == 0) return 1;
  int n = a->array->fn_27_FFF0();
  int m = b->array->fn_27_FFF0();
  if (n > m) n = m;
  for (int i = 0; i < n; i++) {
   Elem* x = a->array->fn_27_FF68(i);
   Elem* y = b->array->fn_27_FF68(i);
   if (!(x->a & y->b) || !(x->b & y->a)) return 0;
  }
  return 1;
 }
 return 0;
}
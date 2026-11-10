#pragma force_active on
#pragma use_lmw_stmw on
extern "C" void fn_80281BBC(int, int, int);
class Class_80486468 {
public:
 virtual void fn_80280E3C();
 virtual void fn_80080A64();
 virtual void fn_80281234();
 virtual void fn_802810D0();
 virtual void fn_80281198();
 virtual void fn_80281294();
 virtual void fn_802812A8();
 virtual void fn_802812D0();
 virtual void fn_802812F0();
 virtual void fn_80281304();
 virtual void fn_80281330();
 virtual int fn_80280FF4();
};
extern "C" int fn_802810D0(Class_80486468 *arg0, int arg1, int arg2) {
 int var_r31;
 int var_r30;
 int var_r29;
 int var_r6;
 int *p = (int *)arg0;
 var_r29 = arg1;
 var_r31 = arg2;
 var_r6 = p[4];
 var_r30 = p[5] - var_r6;
 while (var_r31 > var_r30) {
  fn_80281BBC(var_r29, p[3] + var_r6, var_r30);
  var_r29 += var_r30;
  var_r31 -= var_r30;
  p[4] = p[4] + var_r30;
  if (arg0->fn_80280FF4() != 0) return arg2 - var_r31;
  var_r6 = p[4];
  var_r30 = p[5] - var_r6;
 }
 fn_80281BBC(var_r29, p[3] + var_r6, var_r31);
 p[4] = p[4] + var_r31;
 return arg2;
}
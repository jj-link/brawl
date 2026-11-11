#pragma force_active on

typedef unsigned char u8;
typedef int s32;
extern s32 fn_80232068(void *, s32);
extern void fn_802319FC(s32, void *, u8);
extern s32 fn_8022E920(u8, s32, s32);
extern u8 lbl_8047FD34[];
extern u8 lbl_805298E8[];
extern u8 lbl_805A0D30;
s32 fn_802345E8(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 arg7, s32 arg_sp8)
{
  u8 *var_r31;
  u8 *var_r30;
  s32 var_r29;
  s32 var_r28;
  var_r31 = lbl_805298E8;
  var_r29 = 0;
  var_r30 = var_r31;
  var_r28 = 0;
  for (;;)
  {
    if ((var_r31[8] == 1) && (fn_80232068(var_r30, arg0) == 0))
    {
      if (lbl_805A0D30 >= 4)
      {
        fn_802319FC(0x503, lbl_8047FD34, (lbl_805298E8 + (var_r28 * 9))[6]);
      }
      var_r29 = fn_8022E920((lbl_805298E8 + (var_r28 * 9))[6], arg7, arg_sp8);
      break;
    }
    var_r28 += 1;
    var_r31 += 9;
    var_r30 += 9;
    if (var_r28 >= 5)
    {
      break;
    }
  }

  return var_r29;
}

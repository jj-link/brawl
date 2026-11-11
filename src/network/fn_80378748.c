
#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
extern s32 fn_8035A590(s32);
extern u32 *fn_8035A598(s32, s32);
extern void fn_8035A918(s32, s32);
extern void fn_8035B120(s32, void **);
void fn_80378748(void *arg0)
{
  void *sp8;
  s32 new_var[2];
  s32 var_r28;
  for (var_r28 = fn_8035A590(*((s32 *) (((u8 *) arg0) + 0x10))) - 1; var_r28 >= 0; var_r28--)
  {
    sp8 = (void *) (*fn_8035A598(*((s32 *) (((u8 *) arg0) + 0x10)), var_r28));
    if (((*((s32 *) (((u8 *) sp8) + 0x14))) == 0) && ((*((s32 *) (((u8 *) sp8) + 0x24))) == 0))
    {
      if ((*((s32 *) (((u8 *) sp8) + 0xC))) == 7)
      {
        new_var[1] = fn_8035A590(*((s32 *) (((u8 *) (*((void **) (((u8 *) sp8) + 0x8)))) + 0x10)));
        for (new_var[0] = 0; new_var[0] < new_var[1]; new_var[0]++)
        {
          if ((*fn_8035A598(*((s32 *) (((u8 *) (*((void **) (((u8 *) sp8) + 0x8)))) + 0x10)), new_var[0])) == ((u32) sp8))
          {
            fn_8035A918(*((s32 *) (((u8 *) (*((void **) (((u8 *) sp8) + 0x8)))) + 0x10)), new_var[0]);
            break;
          }
          if (1)
          {
          }
        }

      }
      else
      {
        fn_8035B120(*((s32 *) (((u8 *) (*((void **) (((u8 *) sp8) + 0x8)))) + 0xC)), &sp8);
      }
    }
  }

}

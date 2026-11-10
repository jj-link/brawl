#pragma force_active on
extern int lbl_80599680[];
extern char lbl_804931C0[];
extern char lbl_805996E0[];
void OSReport(const char *, ...);
int fn_803CB978(int, int, int, int);
int fn_803CB990(int, int, int, int);
void fn_803D6224(void *, int, int);
int fn_803EEB9C(int arg0, int arg1, int arg2, int arg3, int *arg4)
{
  int temp_r3;
  int temp_r8;
  char *s;
  int var_r25;
  int var_r30;
  unsigned int var_r24;
  s = lbl_804931C0;
  var_r30 = arg1;
  if (!(lbl_80599680[0] & 2)) {
    *arg4 = 0;
    return 0xF;
  }
  if (lbl_80599680[5] != 0) return 0xF;
  temp_r8 = arg0 * arg3;
  if (temp_r8 == 0) {
    *arg4 = 0;
    return 1;
  }
  var_r25 = arg2 * arg3;
  *arg4 = -1;
  var_r30 = arg1;
  if (!(arg1 & 0x1F)) {
    if (lbl_80599680[4] == 0) {
      *arg4 = 0;
      return 6;
    }
    if (((unsigned int)arg0) == 1) {
      temp_r3 = fn_803CB978(lbl_80599680[2], var_r25, var_r30, temp_r8);
      if (temp_r3 != 0) {
        OSReport(s + 0x4E0, temp_r3);
        *arg4 = 0;
        return 0x15;
      }
    } else {
      temp_r3 = fn_803CB990(lbl_80599680[2], var_r25, var_r30, temp_r8);
      if (temp_r3 != 0) {
        OSReport(s + 0x528, temp_r3);
        *arg4 = 0;
        return 0x15;
      }
    }
    goto done;
  }
  for (var_r24 = 0; var_r24 < ((unsigned int)arg0); var_r24++) {
    if (lbl_80599680[4] == 0) {
      if (var_r24 != 0) {
        *arg4 = var_r24;
        return 0;
      }
      *arg4 = 0;
      return 6;
    }
    fn_803D6224(lbl_805996E0, var_r30, arg3);
    temp_r3 = fn_803CB978(lbl_80599680[2], var_r25, (int)lbl_805996E0, arg3);
    if (temp_r3 != 0) {
      OSReport(s + 0x570, temp_r3);
      if (var_r24 != 0) {
        *arg4 = var_r24;
        return 0;
      }
      *arg4 = 0;
      return 0x15;
    }
    var_r30 += arg3;
    var_r25 += arg3;
  }
done:
  *arg4 = arg0;
  return 0;
}
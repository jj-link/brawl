#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef struct Obj {
 s16 unk0, unk2, unk4;
 u8 pad6[14];
 u8 unk14, unk15, unk16, unk17;
} Obj;
extern void *fn_8022EFF8(s32);
extern void fn_80254D68(s32, s32, void *);
extern u8 lbl_8052D5A8[];
void fn_80254F00(s32 arg0, u8 arg1, s32 arg2, u32 arg3, u8 arg4, u8 arg5) {
 Obj *p = fn_8022EFF8(2);
 u8 *q;
 if (p) {
  p->unk4 = 12;
  q = &p->unk14;
  *q++ = ((arg2 != 0) ? 2 : 0) | 0x81;
  *q++ = 0x11;
  *q++ = arg1;
  *q++ = arg4;
  if (arg2) *q++ = 0;
  else *q++ = lbl_8052D5A8[11];
  *q++ = 0;
  *q++ = arg3;
  *q++ = arg3 >> 8;
  *q++ = 0;
  *q++ = arg5;
  p->unk2 = 10;
  fn_80254D68(arg0, 0, p);
 }
}
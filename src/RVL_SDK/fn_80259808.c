#include <string.h>
#pragma force_active on
typedef struct Obj { unsigned char kind; unsigned char pad; unsigned char addr[6]; unsigned char rest[0x1a]; unsigned short cid; } Obj;
extern Obj *fn_8025AF74(void);
extern void fn_8024A764(void *, unsigned int, unsigned short, unsigned int, unsigned int);
extern void fn_8024A8F4(unsigned short, void *);
extern void fn_802319FC(int, const char *, int);
extern unsigned char lbl_8052D9C0[];
extern char lbl_80484E58[];
void fn_80259808(void *arg0, unsigned short arg1, int arg2, unsigned int arg3) {
 Obj *obj = fn_8025AF74();
 if (obj != 0) {
  obj->kind = 2;
  memcpy(obj->addr, arg0, 6);
  obj->cid = arg1;
  fn_8024A764(arg0, arg3, arg1, 0, 0);
  fn_8024A8F4(arg1, lbl_8052D9C0);
  if (lbl_8052D9C0[0x4630] >= 4) fn_802319FC(0xA0003, lbl_80484E58, obj->cid);
 }
}
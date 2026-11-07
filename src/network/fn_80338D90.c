#include <revolution/OS/OSTime.h>
#pragma force_active on
typedef struct Value { unsigned int a, b, c; } Value;
typedef struct Inner { int x; Value value; unsigned int data[5]; int field24; } Inner;
typedef struct State {
 char pad0[12]; int fieldc; int field10; char pad14[8]; Inner *field1c;
 char pad20[32]; Value value; char pad4c[0x200]; char field24c[9]; char field255[1];
} State;
extern State *lbl_805A0F80;
extern char lbl_80489A00[];
extern void fn_80335638(int, const char *, ...);
extern int fn_80351284(void *);
extern void fn_80350D74(void *, int, void *);
extern unsigned long long fn_80350C0C(void *);
extern int fn_8035126C(void *);
extern int fn_8035121C(void *);
extern void fn_80351154(void *);
extern void fn_80350C44(void *, unsigned int);
extern void fn_80335390(void);
extern void fn_80335450(void);
extern void fn_803520B8(int, void *, unsigned long long, void (*)(void), void (*)(void));
void fn_80338D90(void) {
 const char *base = lbl_80489A00;
 unsigned long long value;
 fn_80335638(0x20, base + 0x1a4);
 if (fn_80351284(lbl_805A0F80->field1c)) {
  fn_80335638(0x20, base + 0x1b8);
  fn_80350D74(&lbl_805A0F80->field1c->data, lbl_805A0F80->field1c->field24, lbl_805A0F80->field24c);
  value = fn_80350C0C(&lbl_805A0F80->field1c->data);
 } else {
  fn_80335638(0x20, base + 0x1e8);
  if (!fn_8035126C(&lbl_805A0F80->value)) {
   fn_80335638(0x20, base + 0x218);
   if (fn_8035121C(&lbl_805A0F80->field1c->value)) {
    fn_80335638(0x20, base + 0x254);
    lbl_805A0F80->value = lbl_805A0F80->field1c->value;
   } else {
    fn_80335638(0x20, base + 0x280);
    fn_80351154(&lbl_805A0F80->value);
   }
  } else {
   unsigned long long time;
   fn_80335638(0x20, base + 0x2ac);
   time = OSGetTime();
   fn_80350C44(&lbl_805A0F80->value, (unsigned int)((time * 0x5d588b656c078965ULL + 0x269ec3ULL) >> 32));
  }
  fn_80350D74(&lbl_805A0F80->value, lbl_805A0F80->fieldc, lbl_805A0F80->field24c);
  value = 0;
 }
 fn_803520B8(lbl_805A0F80->field10, lbl_805A0F80->field255, value, fn_80335390, fn_80335450);
}
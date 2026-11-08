#include <string.h>
#pragma force_active on
typedef struct Config { char pad[12]; int a, b, c; } Config;
typedef struct Context {
 char pad0[0x54]; char io[12]; int limit, used; char pad68[0x10];
 char buf[4]; char *data; char pad80[4]; int size; char pad88[0xd8];
 Config *config; int *array; int index; char pad16c[0x10]; int state;
 char pad180[0x14]; int flag;
} Context;
extern int fn_8035A590(int *);
extern int fn_8035A598(int *, int);
extern int fn_8037B7B4(void *, void *, int);
extern void fn_8037BBB8(void *);
extern int fn_8037BBDC(Context *);
extern int fn_8037C1C0(Context *, void *, int);
extern int fn_80380198(int, Context *, int, int);
extern char lbl_8059FA94[3];
extern char lbl_804908A0[];
int fn_803807A8(Context *self) {
 int count = fn_8035A590(self->array);
 int result;
 if (self->used < self->limit) {
  if (!fn_8037BBDC(self)) return 0;
  if (self->used < self->limit) return 2;
  fn_8037BBB8(self->io);
  if (self->state != 0) return 3;
  if (self->index == count) return 1;
 }
 if (self->state != 0) {
  if (self->config->a != 0 || self->config->b != 0) {
   result = fn_8037C1C0(self, lbl_8059FA94, strlen(lbl_8059FA94));
   if (result == 0) return 0;
   if (result == 2) return 2;
   if (self->state == 1) return 3;
  } else self->state = 0;
 }
 while (self->index < count) {
  int index;
  int item = fn_8035A598(self->array, self->index);
  index = self->index;
  result = fn_80380198(item, self, index == 0, index == fn_8035A590(self->array) - 1);
  if (result == 0) return 0;
  if (result == 2) return 2;
  self->index++;
 }
 if (self->flag != 0 && self->size > 0) {
  if (fn_8037B7B4(self->io, self->data, self->size) == 0) return 0;
  fn_8037BBB8(self->buf);
 }
 if (self->config->a != 0 && self->config->c == 0) {
  if (fn_8037C1C0(self, lbl_804908A0, strlen(lbl_804908A0)) == 0) return 0;
 }
 result = 1;
 if (self->used < self->limit) result = 2;
 return result;
}
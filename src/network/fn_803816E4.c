#include <string.h>
#pragma force_active on
typedef struct Context {
    char pad00[0x10]; int state; char pad14[0x28]; int error;
    char pad40[0xc]; int handle; int result; char pad54[0x48];
    char buffer[4]; char *text; char padA4[0x1c]; char other[0x54];
    int status; char pad118[4]; int offset; int flag;
    char pad124[0x58]; int field17C; char pad180[0x14]; int field194;
} Context;
extern int fn_8037BFCC(Context *, char *, int *);
extern int fn_8037B644(void *, char *, int);
extern int fn_8037BE7C(Context *);
extern int fn_803815CC(Context *);
extern void fn_8037BBB8(void *);
extern void fn_8037BDD4(Context *, int, int);
extern int fn_8035C658(int);
extern char lbl_8059FAD0[3];
void fn_803816E4(Context *self)
{
    char buf[0x400];
    int size = 0x400;
    int result;
    char *p;
    int offset;
    result = fn_8037BFCC(self, buf, &size);
    if (result == 3) return;
    if (result == 1) return;
    if (result == 0) {
        if (self->field194) {
            if (!fn_8037B644(self->other, buf, size)) return;
            if (!fn_8037BE7C(self)) {
                self->flag = 1;
                self->error = 0x11;
                return;
            }
        } else {
            if (!fn_8037B644(self->buffer, buf, size)) return;
        }
    }
    p = strstr(self->text, lbl_8059FAD0);
    if (p) {
        *p = 0;
        offset = p - self->text;
        if (fn_803815CC(self)) {
            self->offset = offset + 2;
            if (self->status == 100 && self->field17C) {
                self->field17C = 0;
                fn_8037BBB8(self->buffer);
                self->state = 6;
                fn_8037BDD4(self, 0, 0);
            } else {
                self->state = 9;
                fn_8037BDD4(self, 0, 0);
            }
        }
    } else if (result == 2) {
        self->flag = 1;
        self->error = 7;
        self->result = fn_8035C658(self->handle);
    }
}
#pragma force_active on
typedef struct Context {
    unsigned char pad0[0x10];
    int state;
    unsigned char pad14[0x38];
    int handle;
    unsigned char pad50[0x11C];
    int field16C;
    unsigned char pad170[0xC];
    int field17C;
    int field180;
} Context;

extern int fn_803807A8(Context *);
extern void fn_8037FA44(Context *);
extern int fn_8035C660(int, int *, int, int);
extern void fn_8037BDD4(Context *, int, int);
extern void fn_8037BE0C(Context *);

void fn_8038141C(Context *self)
{
    int result;
    int oldValue = self->field16C;
    int status = fn_803807A8(self);

    if (status == 0) {
        result = 0;
        fn_8037FA44(self);
        if (fn_8035C660(self->handle, &result, 0, 0) == 1 && result != 0) {
            self->state = 8;
            fn_8037BDD4(self, 0, 0);
        }
    } else {
        if (status == 3) {
            self->field17C = 0;
            return;
        }
        if (oldValue != self->field16C) {
            fn_8037BE0C(self);
        }
        if (status == 1) {
            fn_8037FA44(self);
            self->field180 = 1;
            self->state = 7;
            fn_8037BDD4(self, 0, 0);
        }
    }
}

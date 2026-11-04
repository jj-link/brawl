#pragma force_active on
typedef struct Context {
    char pad0[0x10];
    int field10;
    char pad14[0x28];
    int field3c;
    char pad40[0x14];
    char io[0xc];
    int field60;
    int field64;
    char pad68[0x58];
    char data[0x60];
    int field120;
    char pad124[0x6c];
    char field190[8];
    int field198;
    int field19c;
    int (*callback)(struct Context *, void *);
} Context;
extern int fn_8037BBDC(Context *);
extern void fn_8037BBB8(void *);
extern int fn_8037BFCC(Context *, void *, int *);
extern int fn_8037B644(void *, void *, int);
extern int fn_8037BE7C(Context *);
extern void fn_8037BDD4(Context *, int, int);
void fn_80381010(Context *self) {
    int size;
    char buf[0x401];
    int result;
    if (self->field198 == 0 && self->callback(self, self->field190) == 3) {
        self->field120 = 1;
        self->field3c = 0x11;
        return;
    }
    if (self->field64 < self->field60) {
        if (!fn_8037BBDC(self)) return;
        if (self->field64 < self->field60) return;
        fn_8037BBB8(self->io);
    }
    size = 0x401;
    result = fn_8037BFCC(self, buf, &size);
    if ((unsigned int)(result - 2) <= 1) {
        self->field120 = 1;
        self->field3c = 0x11;
        return;
    }
    if (result == 0 && fn_8037B644(self->data, buf, size)) {
        if (!fn_8037BE7C(self)) {
            self->field120 = 1;
            self->field3c = 0x11;
            return;
        }
        if (self->field19c != 0) {
            self->field10 = 5;
            fn_8037BDD4(self, 0, 0);
        }
    }
}
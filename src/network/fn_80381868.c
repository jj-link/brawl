#pragma force_active on
typedef struct Context {
    char pad0[0xc];
    int mode;
    char pad10[0x2c];
    int error;
    char pad40[0xa4];
    char io[4];
    int data;
    char padEC[4];
    int size;
    char padF4[0x2c];
    int done;
    int count;
    int total;
    char pad12C[0x28];
    int flag;
} Context;

extern int fn_8037B644(void *, void *, int);
extern void fn_8037BDD4(Context *, int, int);

int fn_80381868(Context *self, int arg1, int arg2) {
    int a = 0;
    int b = 0;
    self->count += arg2;
    if (self->count == self->total || self->flag != 0) {
        self->done = 1;
    }
    if (self->mode == 0) {
        if (fn_8037B644(self->io, (void *)arg1, arg2) == 0) {
            return 0;
        }
        a = self->data;
        b = self->size;
    } else if (self->mode == 1) {
        if (arg2 != 0) {
            self->done = 1;
            self->error = 13;
            return 0;
        }
        a = arg1;
        b = arg2;
    } else if (self->mode == 2) {
        a = arg1;
        b = arg2;
    }
    fn_8037BDD4(self, a, b);
    return 1;
}
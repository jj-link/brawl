#pragma force_active on
typedef struct Context {
    char pad0[0x54];
    char io[0xC];
    int size;
    int offset;
    char pad68[0x12C];
    int state;
    char pad198[4];
    int mode;
} Context;

extern int fn_8037B644(void *, void *, int);
extern int fn_8037B7B4(void *, void *, int);
extern void fn_8037BBB8(void *);
extern int fn_8037BBDC(Context *);
extern int fn_8037C104(Context *, void *, int);

int fn_8037C1C0(Context *arg0, void *arg1, int arg2) {
    int temp_r3;
    int var_r6;

    var_r6 = 0;
    if (arg0->state != 0 && arg0->mode == 1) {
        if (fn_8037B7B4(&arg0->io, arg1, arg2) == 0) {
            return 0;
        }
        if (fn_8037BBDC(arg0) == 0) {
            return 0;
        }
        if (arg0->offset >= arg0->size) {
            fn_8037BBB8(&arg0->io);
            return 1;
        }
        return 2;
    }
    if (arg0->offset >= arg0->size) {
        temp_r3 = fn_8037C104(arg0, arg1, arg2);
        var_r6 = temp_r3;
        if (temp_r3 == -1) {
            return 0;
        }
        if (temp_r3 == arg2) {
            return 1;
        }
    }
    if (fn_8037B644(&arg0->io, (char *)arg1 + var_r6, arg2 - var_r6) == 0) {
        return 0;
    }
    return 2;
}
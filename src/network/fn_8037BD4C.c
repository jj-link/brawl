#pragma force_active on
struct X {
    int pad0;
    int a4;
    int pad8;
    int aC;
    char pad10[0x2C];
    int a3C;
    char pad40[0x04];
    int (*fn)(int, int, int, int, int);
    int a48;
    char pad4C[0x9C];
    int aE8;
    char padEC[0x14];
    int a100;
    char pad104[0x20];
    int a124;
};

void fn_8037BD4C(struct X* self) {
    int (*fn)(int, int, int, int, int);
    int val;
    int result;
    fn = self->fn;
    if (fn != 0) {
        if (self->aC == 0) {
            val = self->aE8;
        } else {
            val = 0;
        }
        result = fn(self->a4, self->a3C, val, self->a124, self->a48);
        if (val != 0 && result == 0) {
            self->a100 = 1;
        }
    }
}

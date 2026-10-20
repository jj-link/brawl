#pragma force_active on
typedef struct FnObj {
    char pad[0x18];
    int f18;
} FnObj;

extern "C" void *fn_27_FB52C(FnObj *self, int idx)
{
    int n = (self->f18 >> 30) + idx;
    if (n >= 1) {
        n--;
    }
    return (char *)self + 0x1c + n * 12;
}

#pragma force_active on
typedef struct FtZeldaWork {
    char pad[0xc];
    int *values;
} FtZeldaWork;

extern "C" void fn_104_AB00(FtZeldaWork *self, int value, unsigned int index) {
    self->values[index] *= value;
}

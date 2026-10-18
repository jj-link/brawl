#pragma force_active on
typedef struct FnTarget {
    char pad[0xc];
    int *arr;
} FnTarget;

extern "C" void fn_41_C26C(FnTarget *self, int divisor, int idx) {
    if (divisor == 0) {
        return;
    }
    self->arr[idx] /= divisor;
}

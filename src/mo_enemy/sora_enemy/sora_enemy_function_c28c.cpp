#pragma force_active on
struct FnObj41 {
    char pad[0xc];
    int *arr;
};

extern "C" void fn_41_C28C(FnObj41 *self, int val, int idx)
{
    self->arr[idx] *= val;
}

#pragma force_active on
struct FnS27 {
    char pad[0x54];
    void **arr;
    int count;
};

extern "C" void fn_27_2322E4(FnS27 *self, void *item) {
    self->arr[self->count] = item;
    self->count = self->count + 1;
}

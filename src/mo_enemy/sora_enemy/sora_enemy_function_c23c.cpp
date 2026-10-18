#pragma force_active on
struct FnObj {
    char pad[0xc];
    int *arr;
};

extern "C" void fn_41_C23C(FnObj *obj, unsigned int idx) {
    obj->arr[idx]--;
}

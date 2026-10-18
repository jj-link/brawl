#pragma force_active on
struct Obj {
    int pad[3];
    int *arr;
};

extern "C" void fn_41_C2A4(Obj *o, int v, int i) {
    o->arr[i] -= v;
}

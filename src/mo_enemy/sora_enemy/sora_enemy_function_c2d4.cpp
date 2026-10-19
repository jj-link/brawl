#pragma force_active on
struct S {
    int a;
    int b;
    int c;
    int* arr;
};

extern "C" void fn_41_C2D4(S* self, int value, int index) {
    self->arr[index] = value;
}

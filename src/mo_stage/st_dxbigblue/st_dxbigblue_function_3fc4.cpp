#pragma force_active on
struct Obj {
    char pad[0x188];
    int a;
    float b;
};

extern "C" void fn_81_3FC4(Obj* o, int* a, float* b) {
    *a = o->a;
    *b = o->b;
}

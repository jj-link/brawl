#pragma force_active on
struct S {
    unsigned int pad:6;
    unsigned int f:3;
    unsigned int rest:23;
};

extern "C" void fn_27_295C14(void* self, unsigned int v) {
    ((S*)((char*)self + 8))->f = v;
}

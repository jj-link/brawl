#pragma force_active on
extern "C" void fn_2_848C(void*, int, void*);
struct A { int a[3]; void** p; };
extern "C" void fn_1_6AA4(char* self, void* x) {
    void** p = *(void***)(self + 0xc);
    fn_2_848C(*p, 1, x);
}

#pragma force_active on
struct S {
    unsigned a : 9;
    unsigned b : 9;
    unsigned c : 14;
};

extern "C" void fn_48_B428(void* self, unsigned value) {
    struct S* p = (struct S*)((char*)self + 8);
    p->b = value;
}

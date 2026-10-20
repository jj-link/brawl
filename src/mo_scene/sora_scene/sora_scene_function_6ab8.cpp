#pragma force_active on
extern "C" void fn_2_848C(void*, int, void*);

struct S1 { void* p; };
struct S0 { char pad[0xc]; S1* s; };

extern "C" void fn_1_6AB8(S0* a, void* b) {
    fn_2_848C(a->s->p, 0, b);
}

#pragma force_active on
struct S { char pad[0x28]; void* p; };
extern "C" void fn_80092418(void*);
extern "C" void fn_27_1169C(S* s) {
    if (s->p) {
        fn_80092418(s->p);
    }
}

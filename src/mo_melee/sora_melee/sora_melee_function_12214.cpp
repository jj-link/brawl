#pragma force_active on
extern "C" void fn_8008F3E0(void*);

struct S {
    char pad[0x2c];
    void* p;
};

extern "C" void fn_27_12214(S* s) {
    if (s->p) {
        fn_8008F3E0(s->p);
    }
}

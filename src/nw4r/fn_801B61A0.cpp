#pragma force_active on
extern "C" void fn_801F201C(void*);

extern "C" void fn_801B61A0(unsigned int* self) {
    fn_801F201C((char*)self + 4);
    *self = (*self & ~2u) | 1u;
}

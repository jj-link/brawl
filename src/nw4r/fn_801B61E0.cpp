#pragma force_active on
extern "C" void fn_801F22B0(void*);

extern "C" void fn_801B61E0(unsigned int* self) {
    fn_801F22B0((char*)self + 4);
    *self = (*self & ~1u) | 0xA;
}

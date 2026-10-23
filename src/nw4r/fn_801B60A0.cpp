#pragma force_active on
extern "C" void fn_801F22B0(void*);

extern "C" void fn_801B60A0(unsigned int* self) {
    fn_801F22B0((char*)self + 4);
    *self = (*self & ~2u) | 1u;
}

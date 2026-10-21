#pragma force_active on
extern "C" void fn_801F200C(void*);

extern "C" void fn_801B6120(void* self) {
    fn_801F200C((char*)self + 4);
    unsigned int* flags = (unsigned int*)self;
    *flags = (*flags & ~2u) | 1u;
}

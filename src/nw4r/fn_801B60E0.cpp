#pragma force_active on
extern "C" void fn_801F202C(void*);

extern "C" void fn_801B60E0(unsigned int* self) {
    fn_801F202C((char*)self + 4);
    unsigned int flags = *self;
    *self = (flags & ~2u) | 1u;
}

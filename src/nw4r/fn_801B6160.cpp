#pragma force_active on
extern "C" void fn_801F21B4(void*);

extern "C" void fn_801B6160(unsigned int* self) {
    fn_801F21B4((char*)self + 4);
    *self = (*self & ~2u) | 1u;
}

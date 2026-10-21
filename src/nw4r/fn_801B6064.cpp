#pragma force_active on
extern "C" void fn_801F2284(void*);

extern "C" void fn_801B6064(unsigned int* self) {
    fn_801F2284((char*)self + 4);
    *self &= 0xFFFFFFFD;
}

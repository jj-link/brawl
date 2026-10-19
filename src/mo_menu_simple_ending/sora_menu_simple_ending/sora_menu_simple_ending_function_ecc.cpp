#pragma force_active on
extern "C" void fn_8007EC08(void*, void*, int, int, int);

extern "C" void fn_19_ECC(void* self, int index) {
    fn_8007EC08(*(void**)((char*)self + 0x9ac),
                ((char*)self + 0x4c) + index * 0x30,
                0, 0, 0);
}

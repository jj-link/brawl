#pragma force_active on
extern "C" void* fn_8015C1D0(void* a, int b);
extern "C" void fn_8015C144(void* a, void* b);

extern "C" void* fn_27_500B8(char* self) {
    void* r = fn_8015C1D0(self + 0x98, 0);
    fn_8015C144(self + 0x98, r);
    return r;
}

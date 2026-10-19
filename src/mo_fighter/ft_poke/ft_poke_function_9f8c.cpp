#pragma force_active on
extern "C" void fn_27_3774AC(void*);
extern "C" void fn_27_13604C(void*, void*, unsigned long, void*);

extern "C" void fn_116_9F8C(char* self, void* a, unsigned long b, void* c) {
    if (b == 1) {
        fn_27_3774AC(self + 0x10000 + 0x7fbc);
    }
    fn_27_13604C(self, a, b, c);
}

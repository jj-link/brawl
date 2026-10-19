#pragma force_active on
extern "C" void fn_27_3774AC(void*);
extern "C" void fn_27_13604C(void*, void*, unsigned long, void*);

extern "C" void fn_116_185BC(void* self, void* a2, unsigned long a3, void* a4) {
    if (a3 == 1) {
        fn_27_3774AC(reinterpret_cast<unsigned char*>(self) + 0x1630C);
    }
    fn_27_13604C(self, a2, a3, a4);
}

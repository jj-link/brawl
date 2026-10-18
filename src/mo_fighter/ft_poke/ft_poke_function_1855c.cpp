#pragma force_active on
extern "C" {
extern const float lbl_116_rodata_58;
void fn_27_3772A8(void*);
void fn_27_135468(void*, unsigned int);
}

extern "C" void fn_116_1855C(void* self, unsigned int flags) {
    unsigned char* object = static_cast<unsigned char*>(self);

    if (lbl_116_rodata_58 != *reinterpret_cast<float*>(object + 0x114)) {
        fn_27_3772A8(object + 0x1630C);
    }

    fn_27_135468(self, flags);
}

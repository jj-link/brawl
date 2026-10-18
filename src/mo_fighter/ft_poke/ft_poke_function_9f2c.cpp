#pragma force_active on
extern "C" {
extern const float lbl_116_rodata_8;
void fn_27_3772A8(void*);
void fn_27_135468(void*, unsigned int);

void fn_116_9F2C(void* self, unsigned int flags) {
    if (lbl_116_rodata_8 != *reinterpret_cast<float*>(
            static_cast<unsigned char*>(self) + 0x114)) {
        fn_27_3772A8(static_cast<unsigned char*>(self) + 0x17FBC);
    }
    fn_27_135468(self, flags);
}
}

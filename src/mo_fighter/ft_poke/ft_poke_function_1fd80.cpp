#pragma force_active on
extern "C" {
extern const float lbl_116_rodata_98;
void fn_27_3772A8(void*);
void fn_27_135468(void*, unsigned int);
}

extern "C" void fn_116_1FD80(void* self, unsigned int flags) {
    unsigned char* bytes = static_cast<unsigned char*>(self);

    if (*reinterpret_cast<const float*>(&lbl_116_rodata_98) !=
        *reinterpret_cast<const float*>(bytes + 0x114)) {
        fn_27_3772A8(bytes + 0x11130);
    }

    fn_27_135468(self, flags);
}
